#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
node *head =NULL;
void insertb(int data)
{
    node *new_node = new node;
    new_node->data = data;
    if(head==NULL)
    {
        head=new_node;
        new_node->prev=NULL;
        new_node->next=NULL;
    }
    else
    {
        new_node->next=head;
        head->prev=new_node;
        new_node->prev =NULL;
        head = new_node;
    }
}
void inserte(int data)
{
    node *new_node = new node;
    new_node->data = data;
    if(head==NULL)
    {
        head=new_node;
        new_node->prev=NULL;
        new_node->next=NULL;
    }
    else
    {
        node *temp = head;
        while(temp->next!=NULL)temp=temp->next;
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next=NULL;
    }
}
void inserto(int data)
{
    node *new_node = new node;
    new_node->data = data;
    if(head==NULL)
    {
        head=new_node;
        new_node->prev=NULL;
        new_node->next=NULL;
    }
    else
    {
        node *temp = head;
        while(temp->next!=NULL&&temp->data<data)temp=temp->next;
        temp->prev->next = new_node;
        new_node->prev  =temp->prev;
        temp->prev=new_node;
        new_node->next =temp;
    }
}
void deleteb()
{
    if(head==NULL)
    {
        cout << "list is empty"<<endl;
    }
    else
    {
        node *temp = head;
        head = head ->next;
        head->prev = NULL;
        delete temp;
    }
}
void deletee()
{
    if(head==NULL)
    {
        cout << "list is empty"<<endl;
    }
    else
    {
        node *temp = head ;
        while(temp->next!=NULL)temp = temp ->next;
        temp->prev->next=NULL;
        delete temp;
    }
}
void delete_item(int data)
{
    if(head==NULL)
    {
        cout << "list is empty"<<endl;
    }
    else
    {
        node *temp = head ;
        while(temp->next!=NULL)
        {
            if(temp->data==data)
            {
                temp->prev->next=temp->next;
                temp->next->prev= temp->prev;
            }
            temp = temp ->next;
        }
        if(temp->data==data)
        {
            temp->prev->next=NULL;
            delete temp;
        }
    }
}
void display()
{
    node *temp = head;
    while(temp->next!=NULL)
    {
        cout << temp->data<<" ";
        temp=temp->next;
    }
    cout << temp->data<<endl;
}
void run()
{
    cout << "1. add from begin"<<endl;
    cout << "2. add from end"<<endl;
    cout << "3. add in order"<<endl;
    cout << "4. delete from begin"<<endl;
    cout << "5. delete from end"<<endl;
    cout << "6. delete value"<<endl;
    cout << "7. display elements"<<endl;
    int x; cin >> x;
    if(x==1)
    {
        cout << "please type element!"<<endl;
        int y;cin >>y;
        insertb(y);

    }
    else if(x==2)
    {
        cout << "please type element!"<<endl;
        int y;cin >>y;
        inserte(y);

    }
    else if(x==3)
    {
        cout << "please type element!"<<endl;
        int y;cin >>y;
        inserto(y);

    }
    else if(x==4)
    {
        deleteb();
    }
    else if(x==5)
    {
        deletee();
    }
    else if(x==6)
    {
        cout << "please type the item you want to delete"<<endl;
        int y;cin >>y;
        delete_item(y);
    }
    else display();
    cout << "1. continue"<<endl<<"2. terminate"<<endl;
    int z; cin >>z ;
    if(z==1)run();
    else return;
}
int main()
{
    run();
}


