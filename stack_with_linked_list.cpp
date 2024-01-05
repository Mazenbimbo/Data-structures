#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *top = NULL;
void push(int data)
{
    node *new_node = new node;
    new_node->data=data;
    new_node->next=top;
    top = new_node;
}
void pop()
{
    if(top==NULL)cout << "stack is underflow!"<<endl;
    else {
    node *del  =top;
    top = top->next;
    cout << del->data<<endl;
    delete del;
    }
}
void display()
{
     if(top==NULL)cout << "stack is empty!"<<endl;
    else {
    node *temp = top;
    while(temp->next!=NULL)
    {
        cout << temp->data<<endl;
        temp = temp->next;
    }
    cout << temp->data<<endl;
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

