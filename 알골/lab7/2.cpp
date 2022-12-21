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
double hashinsert = 0, hashsearch = 0;

class HashTable {
private:
    struct node {
        int data;
        struct node *next;
        node(int d, struct node *n) {
            data = d; next = n;
        }
    };
    int m;
    struct node **ht;
public:
    HashTable(int m) {
        this->m = m;
        ht = new node*[m]{NULL};
    }
    int getKey(int data) {
        return data % m;
    }
    void insertHT(int data) {
        int hashKey = getKey(data);
        struct node *x = new node(data, NULL);
        if(ht[hashKey] == NULL) {
            ht[hashKey] = x;
        }
        else {
            x->next = ht[hashKey];
            ht[hashKey] = x;
        }
    }
    struct node* searchData(int data) {
        int hashKey = getKey(data);

        if(++hashsearch && ht[hashKey]->data == data) {
            return ht[hashKey];
        }
        else {
            struct node* curNode = ht[hashKey];
            while(curNode->next) {
                if(++hashsearch && curNode->next->data == data ) {
                    return curNode;
                }
                curNode = curNode->next;
          }
        }
        return NULL;
    }
};


class RBtree {
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

int main()
{
    srand((unsigned int)time(NULL));

    int n;
    cin >> n;
    int **tmp = new int *[n];
    int *a = new int[n];
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
        t3.insert(a[i], a[i]);
    }
    double t3_insertcmp = insertcmp;
    insertcmp = 0;
    for(int i = 0; i < n; i++) {
        t3.search(a[i]);
    }
    double t3_searchcmp = searchcmp;
    searchcmp = 0;

    HashTable h1(11);
    HashTable h2(101);
    HashTable h3(1009);
    for(int i = 0; i < n; i++) {
        h1.insertHT(a[i]);
    }
    for(int i = 0; i < n; i++) {
        h1.searchData(a[i]);
    }
    double h1_hashsearch = hashsearch;
    double h1_hashinsert = hashinsert;
    hashsearch = 0;
    hashinsert = 0;
        for(int i = 0; i < n; i++) {
        h2.insertHT(a[i]);
    }
    for(int i = 0; i < n; i++) {
        h2.searchData(a[i]);
    }
    double h2_hashsearch = hashsearch;
    double h2_hashinsert = hashinsert;
    hashsearch = 0;
    hashinsert = 0;
        for(int i = 0; i < n; i++) {
        h3.insertHT(a[i]);
    }
    for(int i = 0; i < n; i++) {
        h3.searchData(a[i]);
    }
    double h3_hashsearch = hashsearch;
    double h3_hashinsert = hashinsert;
    

    cout << "-------------------구축---------------------\n";
    cout << t3_insertcmp/n << " : T3의 구축 시 평균 비교 횟수" << endl;
    cout << h1_hashinsert/n << " : Hash Table 크기가 11인 경우의 구축 시 평균 비교 횟수" << endl;
    cout << h2_hashinsert/n << " : Hash Table 크기가 101인 경우의 구축 시 평균 비교 횟수" << endl;
    cout << h3_hashinsert/n << " : Hash Table 크기가 1009인 경우의 구축 시 평균 비교 횟수\n" << endl;
    cout << "-------------------탐색---------------------\n";
    cout << t3_searchcmp/n << " : T3의 평균 비교 횟수 " << endl;
    cout << h1_hashsearch/n << " : Hash Table 크기가 11인 경우 평균 비교 횟수" << endl;
    cout << h2_hashsearch/n << " : Hash Table 크기가 101인 경우 평균 비교 횟수" << endl;
    cout << h3_hashsearch/n << " : Hash Table 크기가 1009인 경우 평균 비교 횟수" << endl;

}