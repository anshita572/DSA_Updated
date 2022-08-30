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
node *reverseIterative(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *forward;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
node *reverse_k(node *&head, int k)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }
    node*temp=head;
    int len;
    while(temp!=NULL)
    {temp=temp->next;
    len++;}
    if(len/k==0)
    {return head;}
    // we will reverse 1 grp and recursion will reverse rest of the groups
    node *prev = NULL;
    node *curr = head;
    node *forward;
    int count = 0;
    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    if (forward != NULL)
    {
        // head->next = reverse_k(forward, k); or
        node*recursionKaAns=reverse_k(forward, k);
        head->next=recursionKaAns;
        len--;
    }
    return prev;
}
int main()
{
    node *node1 = new node(1);
    node *head = node1;
    node *tail = node1;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    insertAtTail(tail,6);
    printNode(head);
    cout<<endl;
    int k=4;
    head=reverse_k(head,k);
 printNode(head);
    return 0;
}
