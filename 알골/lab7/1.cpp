#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define infoNIL 0
#define itemMIN -1
#define black 0
#define red 1
typedef int itemType; 
typedef double infoType;

double searchcmp = 0, insertcmp = 0;

class RBtree{
private:
    struct node {
        itemType key, tag;
        infoType Info;
        struct node *l, *r;
        node(itemType k, infoType i, itemType t, struct node *ll, struct node *rr) { 
        key = k; Info = i; tag = t; l = ll; r = rr; 
        };
    }; 
    struct node *head, *tail, *x, *p, *g, *gg, *z;
public:
    RBtree(int max) { 
        z = new node( 0, infoNIL, black, 0, 0); 
        z->l = z; z->r = z; 
        head = new node(itemMIN, infoNIL, black, z, z); 
    }
    void insert(itemType k, infoType info);
    struct node* rotate(itemType k, struct node *y) { 
    struct node *high, *low; 
    high = (k< y->key) ? y->l : y->r; 
    insertcmp++;
    if (k < high->key) { low = high->l; high->l = low->r; low->r = high; } 
    else { low = high->r; high->r = low->l; low->l = high; } 
    insertcmp++;
    if (k < y->key) y->l = low; else y->r = low; 
    insertcmp++;
    return low;
}
    void split(itemType k);
    infoType search(itemType k);
    // Red-Black Tree의 값을 탐색 기능 구현
};

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
    void traverse(RBtree *t3);
    void traverse(struct node *t, RBtree *t3);
}; 

infoType BST::BSTsearch(itemType v) { 
     struct node *x = head->r; 
     z->key = v;  // 아래 반복문을 간결히 만들기 위함
     while (++searchcmp && v != x->key){
          x = (v < x->key) ? x->l : x->r; 
     }
     return x->info; 
} 
void BST::BSTinsert(itemType v, infoType info) { 
     struct node *p, *x; 
     p = head; x = head->r; 
     while (x != z && ++insertcmp) {
         p = x; x = (v < x->key) ? x->l : x->r; 
        } 
     x = new node(v, info, z, z);
     if (v < p->key) p->l = x; else p->r = x; 
     insertcmp++;
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

void RBtree::split(itemType k) { 
    x->tag = red; x->l->tag = black; x->r->tag = black; 
    if (p->tag) { 
        g->tag = red; 
        if (k<g->key != k<p->key && ++insertcmp) p = rotate(k, g); 
        x = rotate(k, gg); 
        x->tag = black; 
    } 
}  

void RBtree::insert(itemType k, infoType info) { 
    x = head; p = head; g = head; 
    while (x != z && ++insertcmp) { 
       gg = g; g = p; p = x; 
        x = (k < x->key) ? x->l :  x->r; 
        if (x->l->tag && x->r->tag) split(k); 
    } 
    x = new node(k, info, red, z, z); 
    if (k < p->key) p->l = x; else p->r = x; 
    insertcmp++;
    split(k); head->r->tag = black; 
} 

infoType RBtree::search(itemType k) {
    struct node *x = head->r; 
     z->key = k;  // 아래 반복문을 간결히 만들기 위함
     while (++searchcmp && k != x->key){
          x = (k < x->key) ? x->l : x->r; 
     }
     return x->Info; 
}

void BST::traverse(RBtree *t3)
{
    traverse(head->r, t3);
}

void BST::traverse(struct node *t, RBtree *t3)
{
    if (t != z)
    {
        traverse(t->l, t3);
        t3->insert(t->key, t->key);
        traverse(t->r, t3);
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
    BST t2(n);
    RBtree t3(n);
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
    double t1_insertcmp = insertcmp;
    insertcmp = 0;
    for(int i = 0; i < n; i++) {
        t1.BSTsearch(a[i]);
    }
    double t1_searchcmp = searchcmp;
    searchcmp = 0;

    t1.traverse(&t2);   //중위순회로 t2에 저장
    double t2_insertcmp = insertcmp;
    insertcmp = 0;
    for(int i = 0; i < n; i++) {
        t2.BSTsearch(a[i]);
    }
    double t2_searchcmp = searchcmp;
    searchcmp = 0;

    t1.traverse(&t3);   //중위순회로 t3에 저장
    double t3_insertcmp = insertcmp;
    insertcmp = 0;
    for(int i = 0; i < n; i++) {
        t3.search(a[i]);
    }
    double t3_searchcmp = searchcmp;


    cout << t1_insertcmp/n << " : T1 (구축시 평균 비교 횟수)" << endl; 
    cout << t2_insertcmp/n << " : T2 (구축시 평균 비교 횟수)" << endl; 
    cout << t3_insertcmp/n << " : T3 (구축시 평균 비교 횟수)\n" << endl; 

    cout << t1_searchcmp/n << " : T1 (탐색시 평균 비교 횟수)"  << endl;
    cout << t2_searchcmp/n << " : T2 (탐색시 평균 비교 횟수)"  << endl;
    cout << t3_searchcmp/n << " : T3 (탐색시 평균 비교 횟수)"  << endl;

}