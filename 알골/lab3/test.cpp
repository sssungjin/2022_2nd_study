#include <iostream>
#include <ctime>
using namespace std;

typedef int itemType;

int N; int comp[2], change[2]; 
itemType *B = new itemType[N]; 

void insertion(itemType a[],  int n, int idx) 
{ 
    int i, j; itemType v; 
    for (i = 1; i < n; i++) { 
       v = a[i]; j = i; 
       while ((j>0 && a[j-1] > v) || comp[idx]++ == -1) { a[j] = a[j-1]; j--; change[idx]++;} 
       a[j] = v; change[idx]++;
     } 
}


void sort(itemType **a, int n) 
{
    int i, j; itemType v, v2;
    for (i = 1; i < n; i++) { 
       v = a[i][0]; v2 = a[i][1]; j = i; 
       while (j>0 && a[j-1][0] > v) { a[j][0] = a[j-1][0]; a[j][1] = a[j-1][1]; j--; } 
       a[j][0] = v; a[j][1]=v2;
    }
    for(int i=0;i<n;i++) B[i]=a[i][1];
}

int main(){
    cin>>N;
    itemType *A = new itemType[N]; itemType **tmp = new itemType*[N];   //tmp : B를 생성하기 위한 이중포인터
    srand((unsigned)time(NULL)); 

    for(int i=N;i>0;i--) A[N-i]=i;
    for(int i=0;i<N;i++){
        tmp[i]=new int[2];
        tmp[i][0]=(1+rand()%N);
        tmp[i][1]=i+1;
    } 
    
    sort(tmp, N);                      //이걸 Data A랑 Data B 사이에 넣으면 A가 변경됨;;
    for(int i=0; i<N; i++) delete[] tmp[i];
    delete[] tmp;
    
    cout<<"Data A: ";
    for(int i=0;i<N;i++){cout<<A[i]<<' ';} cout<<endl;    
    
    cout<<"Data B: ";
    for(int i=0;i<N;i++){cout<<B[i]<<' ';} cout<<endl;
    insertion(A, N, 0); insertion(B, N, 1);
    
}