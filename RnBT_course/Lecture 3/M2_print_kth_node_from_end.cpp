#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;    // Pointer of node type
    node(int data) // Parameterized constructor
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head; // head has address of node1 and now temp will store that address
    head = temp;       // ab head will store address of temp (temp will be the first node after inserting)
}
void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
    // OR
    // tail=tail->next;
}
//Print LL recursively
void printNode(node *&head)
{ //base case
   if(head==NULL)
   {return;}
   cout<<head->data<<" ";
   printNode(head->next);
}
void kthNode(node *&head,int& k)
{if(head==NULL) //base case
{return;}
kthNode(head->next,k);
//when base case is reached(control will reach Line 41),vaapis jaate vakt do k--
k--;
if(k==0)
{cout<<head->data;}}
int main()
{
    node *node1 = new node(5);
    node *head = node1;
    node *tail = node1;
    insertAtTail(tail, 4);
    insertAtTail(tail, 1);
    insertAtTail(tail, 3);
    insertAtTail(tail, 2);
    printNode(head);
    cout<<endl;
    int k=3;
    kthNode(head,k);

    return 0;
}
