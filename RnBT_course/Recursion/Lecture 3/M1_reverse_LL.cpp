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
// Print LL recursively
void printNode(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    printNode(head->next);
}
//Reverse LL recursively
node*reverse(node*&head)
{if(head==NULL || head->next==NULL)
{return head;}
node *newHead=reverse(head->next);
head->next->next=head;
head->next=NULL;
return newHead;}

int main()
{
    node *node1 = new node(1);
    node *head = node1;
    node *tail = node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    printNode(head);
    cout<<endl;
    cout<<"Reversed : ";
    head=reverse(head);
    printNode(head);

    return 0;
}
