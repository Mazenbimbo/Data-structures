#include <bits/stdc++.h>
using namespace std;
int top = -1;
int sz = 5;
int a[5];
bool isEmpty()
{
    return (top==-1);
}
bool isFull()
{
    return (top==sz-1);
}
void push(int element)
{
    if(isFull())cout << "stack overflow!"<<endl;
    else{
        top++;
        a[top]= element;
    }
}
void pop()
{
    if(isEmpty())cout << "stack underflow!"<<endl;
    else {
    int poped_element = a[top];
    top--;
    cout << poped_element << endl;
    }
}
void display()
{
    int x = top;
    if(isEmpty())cout << "stack is empty!"<<endl;
    else {
    while(!isEmpty())
    {
        cout << a[top]<<endl;
        top--;
    }
    top = x;
    }
}
void run()
{
    cout << "1. add element"<<endl;
    cout << "2. pop element"<<endl;
    cout << "3. display elements"<<endl;
    int x; cin >> x;
    if(x==1)
    {
        cout << "please type element!"<<endl;
        int y;cin >>y;
        push(y);

    }
    else if(x==2)
    {
        cout << "the poped element is :"<<endl;
        pop();
    }
    else if(x==3)
    {
        display();
    }
    cout << "1. continue"<<endl<<"2. terminate"<<endl;
    int z; cin >>z ;
    if(z==1)run();
    else return;
}
int main()
{
    run();
}

