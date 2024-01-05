///this program is missing dynamic size !
///this program need to be more user friendly in the user interface side !
#include <bits/stdc++.h>
using namespace std;
int rare = -1, frontt =-1;
int sz = 5;
int queuee[5];
bool isEmpty()
{
    return (rare==-1||frontt>rare);
}
bool isFull()
{
    return (rare==sz-1);
}
void enqueue(int data)
{
    if(isFull())cout << "queue is full!"<<endl;
    else
    {
        if(isEmpty())frontt++;
        rare++;
        queuee[rare] = data;
    }
}
void dequeue()
{
    if(isEmpty())cout << "queue is empty!"<<endl;
    else
    {
        frontt++;
    }
}
void peek()
{
    cout << queuee[frontt]<<endl;
}
void display()
{
    for(int i=frontt;i<=rare;i++)
    {
        cout << queuee[i]<<" ";
    }
    cout << endl;
}
void run()
{
    cout << "1. Enqueue"<<endl;
    cout << "2. Dequeue"<<endl;
    cout << "3. display"<<endl;
    cout << "4. peek"<<endl;
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
        peek();
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

