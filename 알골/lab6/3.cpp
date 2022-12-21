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
     void traverse(BST *t2);
     void traverse(struct node *t, BST *t2);
}; 

infoType BST::BSTsearch(itemType v) { 
     struct node *x = head->r; 
     z->key = v;  // 아래 반복문을 간결히 만들기 위함
     while (++datacmp && v != x->key){
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

void BST::traverse(BST *t2)
{
    traverse(head->r, t2);
}

void BST::traverse(struct node *t, BST *t2)
{
    if (t != z)
    {
        traverse(t->l, t2);
        t2->BSTinsert(t->key, t->key);
        traverse(t->r, t2);
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    int n;
    cin >> n;
    int **tmp = new int *[n];
    int *a = new int[n];
    BST t1(n);
    BST t3(n);
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
    for(int i = 0; i < n; i++) {
        t1.BSTsearch(a[i]);
    }
    cout << "T1 average cmp : " << datacmp/n << endl;
    datacmp = 0;
    t1.traverse(&t3);
    for(int i = 0; i < n; i++) {
        t3.BSTsearch(a[i]);
    }
    //t2.print();   //t3출력
    //cout << "\n--------------------\n";
    cout << "T3 average cmp : " << datacmp/n << endl;
}