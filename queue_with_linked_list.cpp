#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data ;
    node *next;
};
node *frontt,*rare;
void enqueue(int data)
{
    node *new_node =new node;
    new_node->data = data;
    new_node->next = NULL;
    if(rare==NULL&&frontt==NULL)
    {
        frontt=new_node;
        rare = new_node;
    }
    else
    {
        rare->next = new_node;
        rare = new_node;
    }
}
void dequeue()
{
    node *temp = frontt;
    frontt=frontt->next;
    delete temp;
}
void display()
{
    node *temp = frontt;
    while(temp->next!=NULL)
    {
        cout << temp->data<<" ";
        temp=temp->next;
    }
    cout << temp->data<<endl;
}
int cnt()
{
    int ctr=0;
    node *temp = frontt;
    while(temp->next!=NULL)
    {
        ctr++;
        temp=temp->next;
    }
    return ctr+1;
}
void run()
{
    cout << "1. enqueue"<<endl;
    cout << "2. dequeue"<<endl;
    cout << "3. display"<<endl;
    cout << "4. count"<<endl;
    int x; cin >> x;
    if(x==1)
    {
        cout << "please type element!"<<endl;
        int y;cin >>y;
        enqueue(y);

    }
    else if(x==2)
    {
        dequeue();
    }
    else if(x==3)
    {
        display();
    }
     else if(x==4)
    {
        cout << cnt()<<endl;
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

