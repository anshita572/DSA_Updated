//Done iteratively
//Doubt : recursively
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
void printNode(node *&head,int i,int target)
{
   if(head==NULL || i == target)
   {cout<<head->data<<" ";
    return;}
   
   printNode(head->next,i+1,target);

}
void kthNode(node* &head,int &k)
{node*temp=head;
int len=0;
while(temp!=NULL)
{temp=temp->next;
len++;}
// Iterative
// temp=head;
// for (int i = 0; i < len-k; i++)
// {
//     temp=temp->next;
// }
// cout<< temp->data;
// Recursive
printNode(head,0,len-k);

}

int main()
{
    node *node1 = new node(1);
    node *head = node1;
    node *tail = node1;
    // printNode(head);
    insertAtTail(tail, 2);
    // printNode(head);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    // printNode(head);
    cout<<endl;
    int k=2;
  kthNode(head,k);

    return 0;
}
