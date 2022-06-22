#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;    // Pointer of node type
    node(int data) // Parameterised constructor
    {
        this->data = data;
        this->next = NULL; //initially starting m single node
    }
    ~node() //destructor (required for delete function)
    {
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
    }
    

};
void insertAtHead(node *&head, int d) // d is data
{
    node *temp = new node(d); // dynamic allocation
    temp->next = head;        // head has address of node1 and now temp will store that address
    head = temp;              // ab head will store address of temp (temp will be the first node after inserting)
}
void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
    // OR
    // tail=tail->next;
}
void insertAtposition(node *&head, node *&tail, int d, int position)
{
    int count = 1; // currently at first node
    node *temp = head;
    node *nodeToInsert = new node(d);
    // if inserting at beginning
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    // if inserting at end
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
    }

    while (count < position - 1) // jis position par newNode insert krni h ,usse previous wali node pe pahaunchna h
    {
        temp = temp->next;
        count++;
    }
    nodeToInsert->next = temp->next; // nodeToBeInserted m uski next node ka address store krna
    temp->next = nodeToInsert;       // storing address of nodeToBeInserted in the previous node
}
//Delete function
void deleteNode(node *&head,int position)
{
//Case 1 : If the element is to be deleted from beginning (i.e. 0th position)

if(position==1)
{node*temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
}

//Case 2 :If the element is to be deleted from a particular position(any middle element or last)
else{
node*curr=head;
node*prev=NULL;
int count=1;
while(count<position)
{
    prev=curr;
    curr=curr->next;
    count++;
}
prev->next=curr->next;//storing address contained in node to be deleted(of next node)in current node(prev->next)
curr->next=NULL;//storing NULL in node to be deleted
delete curr;
}}

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
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    //printNode(head);
    insertAtTail(tail, 12);
   // printNode(head);
    insertAtTail(tail, 15);
   // printNode(head);
    insertAtTail(tail, 18);
  //  printNode(head);
    // 10 12 15 18
    insertAtposition(head, tail, 20, 3); // 10 12 20 15 18
    //printNode(head);
    insertAtposition(head, tail, 25, 1); // 25 10 12 20 15 18
   // printNode(head);
    insertAtposition(head, tail, 28, 7); // 25 10 12 20 15 18 28
    printNode(head);
    deleteNode(head,4);//25 10 12 15 18 28
    printNode(head);
    deleteNode(head,1);//10 12 15 18 28
    printNode(head);
    deleteNode(head,5);//10 12 15 18
    printNode(head);

    return 0;
}