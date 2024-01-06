#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right;
    node *left;
    node()
    {
        right = NULL;
        left = NULL;
    }
};
node *root = NULL;
void insertt(node *&cur,int item)
{
    if(cur==NULL)
    {
        node *new_node = new node;
        new_node->data =item;
        cur = new_node;
    }
    else if(cur->data>item)
    {
        insertt(cur->left,item);
    }
    else insertt(cur->right,item);
}
node *min_node(node *temp)
{
    if(temp==NULL){return NULL;}
    while(temp->left!=NULL)temp=temp->left;
    return temp;
}
node *max_node(node *temp)
{
    if(temp==NULL){return NULL;}
    while(temp->right!=NULL)temp=temp->right;
    return temp;
}
void deletee(node *cur,int item)
{
    if(cur==NULL)cout << "not found"<<endl;
    else if(cur->data==item)
    {
        if(cur->right==NULL&&cur->left==NULL)
        {
            cur = NULL;
        }
        else if(cur->right!=NULL&&cur->left==NULL)
        {
            node *cur_right = cur->right;
            delete cur;
            cur = cur_right;
        }
        else if(cur->right==NULL&&cur->left!=NULL)
        {
            node *cur_left = cur->left;
            delete cur;
            cur = cur_left;
        }
        else
        {
            node *save_min = min_node(cur->right);
            cur->data = save_min->data;
            deletee(cur->right,save_min->data);
        }
    }
    else if(cur->data<item)deletee(cur->right,item);
    else if(cur->data>item)deletee(cur->left,item);
}
void inorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout << temp->data<<" ";
        inorder(temp->right);
    }
}
void preorder(node *temp)
{
    if(temp!=NULL)
    {
        cout << temp->data<<" ";
        inorder(temp->left);
        inorder(temp->right);
    }
}
void postorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        inorder(temp->right);
        cout << temp->data<<" ";
    }
}
void run()
{
    cout << "1. add element"<<endl;
    cout << "2. delete element"<<endl;
    cout << "3. display inorder"<<endl;
    cout << "4. display postorder"<<endl;
    cout << "5. display preorder"<<endl;
    int x; cin >> x;
    if(x==1)
    {
        cout << "please type element!"<<endl;
        int y;cin >>y;
        insertt(root,y);

    }
    else if(x==2)
    {
        cout << "please type an element to delete !"<<endl;
        int y;cin >>y;
        deletee(root,y);
    }
    else if(x==3)
    {
        inorder(root);
    }
     else if(x==4)
    {
        postorder(root);
    }
     else if(x==5)
    {
        preorder(root);
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

