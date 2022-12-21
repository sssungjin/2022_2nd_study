#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int *list = new int(n);

    for(int i = 0; i < n; i++)
        cin >> list[i];
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << list[i] << " ";
    delete [] list;
}