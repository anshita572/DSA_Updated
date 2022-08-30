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
{
   if(head==NULL) //base case
   {return;}
   cout<<head->data<<" ";
   printNode(head->next);//recursive call

}
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    // printNode(head);
    insertAtTail(tail, 12);
    // printNode(head);
    insertAtTail(tail, 15);
    printNode(head);

    return 0;
}
