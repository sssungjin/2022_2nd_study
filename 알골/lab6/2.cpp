#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

double datacmp = 0;
#define infoNIL 0
#define itemMIN -1
typedef int itemType; 
typedef double infoType;
class BST {  
private: 
     struct node { 
          itemType key; infoType info; 
          struct node *l, *r; 
          node(itemType k, infoType i, struct node *ll, struct node *rr)  // node 생성시 초기값 부여 가능 
            { key = k; info = i; l = ll; r = rr; }; 
     }; 
     struct node *head, *z; // z : List의 끝을 대표하는 node pointer – NULL에 해당
public: 
     BST(int max) { 
          z = new node( 0, infoNIL, 0, 0); 
          head = new node(itemMIN, infoNIL, z, z); 
     } 
     ~BST() {
        delete z;
        delete head;
     } 
     infoType  BSTsearch(itemType v); 
     void BSTinsert(itemType v, infoType info); 
     void BSTdelete(itemType v);
     void traverse();
     void traverse(struct node *t);
     void visit(struct node *t);
}; 

infoType BST::BSTsearch(itemType v) { 
     struct node *x = head->r; 
     z->key = v;  // 아래 반복문을 간결히 만들기 위함
     while (v != x->key){
          x = (v < x->key) ? x->l : x->r; 
     }
     return x->info; 
} 
void BST::BSTinsert(itemType v, infoType info) { 
     struct node *p, *x; 
     p = head; x = head->r; 
     while (x != z) {
         p = x; x = (v < x->key) ? x->l : x->r; 
        } 
     x = new node(v, info, z, z);
     if (v < p->key) p->l = x; else p->r = x; 
}

void BST::BSTdelete(itemType v) { 
     struct node *x = head->r, *p, *t, *c; 
     p=head;
     while (x!=z && ++datacmp && x->key !=v)  {
          p=x; 
          x = (v < x->key) ? x->l : x->r; 
     }
     if(x==z) return; 
     else t=x; 
     if(t->r == z) x=t->l; 
     else if(t->r->l == z) {
          x=t->r; x->l = t->l; 
     } else {
          c=x->r; while(c->l->l !=z) c=c->l; 
          x=c->l; c->l = x->r;
          x->l=t->l; x->r=t->r;
     }
     datacmp++;
     free(t); 
     if(v<p->key) p->l =x; else p->r=x;
     datacmp++;
}

void BST::traverse()
{
    traverse(head->r);
}

void BST::traverse(struct node *t)
{
    if (t != z)
    {
        traverse(t->l);
        visit(t);
        traverse(t->r);
    }
}
void BST::visit(struct node *t)
{
    cout << t->key << " ";
}


int main()
{
    srand((unsigned int)time(NULL));

    int n;
    cin >> n;
    int **tmp = new int *[n];
    int *a = new int[n];
    BST t1(n);
    for (int i = 0; i < n; i++)
    {
        tmp[i] = new int[2];
        tmp[i][0] = (1 + rand() % n);
        tmp[i][1] = i + 1;
    }
    int temp, temp_1;
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - i) - 1; j++) {
			if (tmp[j][0] > tmp[j + 1][0]) {
				temp = tmp[j][0];
				tmp[j][0] = tmp[j + 1][0];
				tmp[j + 1][0] = temp;

                temp_1 = tmp[j][1];
				tmp[j][1] = tmp[j + 1][1];
				tmp[j + 1][1] = temp_1;
			}
		}
	}
    for (int i = 0; i < n; i++)
    {
        a[i] = tmp[i][1];
    }

    for(int i = 0; i < n; i++) {
        t1.BSTinsert(a[i], a[i]);
    }

    for(int i = 0; i < n/10; i++) {
        t1.BSTdelete(a[i*10+rand() % 9]);
    }
    // t.traverse();
    // cout << "\n------------------------------\n";
    cout << datacmp/(n/10) << " (T2의 평균 비교횟수)\n";
}