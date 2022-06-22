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
    ~node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};
void insertAtHead(node *&head, node *&tail, int d)
{
    if (head == NULL) // if empty LL
    {
        node *temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(node *&head, node *&tail, int d)
{
    if (tail == NULL) // if empty LL
    {
        node *temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insert(node *&head, node *&tail, int d, int position)
{
    node *temp = head;
    // if inserting at beginning
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    // if inserting at tail
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }
    // if inserting at any position
    node *newNode = new node(d);

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}
void deleteNode(node *&head, int position)
{
    node *temp = head;
    if (position == 1) // deleting head
    {
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        int count = 1;
        node *prevNode = NULL;
        node *currNode = head;
        while (count < position)
        {
            prevNode = currNode;
            currNode = currNode->next;
            count++;
        }
        prevNode->next = currNode->next;
        currNode->next = NULL;
     //   currNode->next->prev = currNode->prev;
        currNode->prev = NULL;
        delete currNode;
    }
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
    // node *n1 = new node(10);
    node *head = NULL; // empty LL initially
    node *tail = NULL;
    // printNode(head); // 10
    insertAtTail(head, tail, 20);
    printNode(head); // 10 20
    insertAtTail(head, tail, 30);
    printNode(head); // 10 20 30
    insertAtTail(head, tail, 40);
    printNode(head);           // 10 20 30 40
    insert(head, tail, 50, 3); // 10 20 50 30 40
    printNode(head);
    insert(head, tail, 60, 1); // 60 10 20 50 30 40
    printNode(head);
    insert(head, tail, 70, 6); // 60 10 20 50 30 40 70
    printNode(head);
    deleteNode(head, 1);
    printNode(head);
    deleteNode(head, 3);
    printNode(head);
    deleteNode(head, 4);
    printNode(head);
    cout << "Length of linked list : " << getLength(head);
    return 0;
}