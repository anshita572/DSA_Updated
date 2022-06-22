// Singly circular linked list
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *head;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};
void insert(node *&tail, int element, int data)
{

    // empty LL
    if (tail == NULL)
    {
        node *temp = new node(data);
        tail = temp;
        temp->next = temp; // pointing to itself
    }
    else // non empty LL and assuming that the element is present in LL
    {
        node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // when element found
        node *temp = new node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deleteNode(node *&tail, int element)
{
    node *prev = tail;
    node *curr = prev->next;
    // if LL is empty
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
    }
    else // assuming that the element is present in LL
    {
        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        // single node present
        if (curr == prev)
        {
            tail = NULL;
        }
        //>=2 nodes present
        else
        {
            if (tail == curr) // if first node is to be deleted
            {
                tail = prev;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
}

void printNode(node *&tail)
{
    if (tail == NULL)
    {
        cout << "Linked List is Empty " << endl;
        return;
    }
    node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
int main()
{
    node *tail = NULL;
    insert(tail, 1, 3); // initailly empty LL
    printNode(tail);    // 3
    insert(tail, 3, 5);
    printNode(tail); // 3 5
    insert(tail, 5, 7);
    printNode(tail); // 3 5 7
    insert(tail, 7, 9);
    printNode(tail); // 3 5 7 9
    insert(tail, 3, 4);
    printNode(tail); // 3 4 5 7 9
    deleteNode(tail, 5);
    printNode(tail); // 3 4 7 9
    deleteNode(tail, 3);
    printNode(tail); // 9 4 7 (since this is a circular LL)
    deleteNode(tail, 7);
    printNode(tail); // 9 4
    deleteNode(tail, 9);
    printNode(tail); // 4
    deleteNode(tail, 4);
    printNode(tail); // empty

    return 0;
}