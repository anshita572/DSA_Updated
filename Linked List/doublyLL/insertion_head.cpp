#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *head;
    node *prev;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(node* &head,int d)
{
    node*temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;

}
void printNode(node *&head)
{
    node *temp = head;
    while (temp != NULL) // loop until temp reaches the last node and points to NULL
    {
        cout << temp->data << " "; // printing data of node to which temp is pointing
        temp = temp->next;         // updating temp(like temp++)
    }
    cout << endl;
}
int getLength(node *&head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
int main()
{
    node *n1 = new node(10);
    node *head = n1;
    printNode(head);
    insertAtHead(head,20);
    printNode(head);
    insertAtHead(head,30);
    printNode(head);
    insertAtHead(head,40);
    printNode(head);
    cout <<"Length of linked list : "<< getLength(head);
    return 0;
}