#include <iostream>
using namespace std;

typedef double itemType;

class Stack2
{
    public:
       Stack2()
       {
        head = nullptr;
       }
       ~Stack2()
       {
        delete head;
       }
       void push(itemType v)
       {
            z = new node();
            z -> key = v;
            z -> next = head;
            head = z;
       }
       itemType pop()
       {    
        itemType a;
        a = head -> key;
        head = head -> next;
        return a;
            
       }
       int empty()
       {
            if(head -> next == nullptr)
                return 1;
            else
                return 0; 
       }

    private:
       struct node 
        { 
            itemType key; 
            struct node *next; //다음스택 주소
        };
       struct node *head, *z;
};

int main()
{
    char c; Stack2 stk; double x; 
    while ((c = cin.get()) != '\n') 
    { 
        x = 0; 
        while (c == ' ') cin.get(c); 
        if (c == '+') x = stk.pop() + stk.pop(); 
        if (c == '*') x = stk.pop() * stk.pop();
        if (c == '-') {
            double a = stk.pop();
            double b = stk.pop();
            x = b - a;
        };
        if (c == '/') {
            double a = stk.pop();
            double b = stk.pop();
            x = b / a;
        };
        while (c>='0' && c<='9') 
            { x = 10*x + (c-'0');  cin.get(c); } 
        stk.push(x); 
    }
    
    double num = stk.pop();
    if((num - (int)num) == 0) {
        cout << num << '\n';
    }
    else {
    cout << fixed;
    cout.precision(2);
    cout <<  num << '\n'; 
    }
}