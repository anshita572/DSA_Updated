// https://bit.ly/3r1rCIP

// Following is the Linked List node structure
#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *kReverse(Node *head, int k)
{
    // base case
    if (head == NULL)
    {
        return head;
    }
    // Step 1 : Reverse k nodes
    int count = 0;
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;
    while (curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
        
    }
    // Step 2 : recursive call
    if (forward != NULL)
    {
        head->next = kReverse(forward, k);
    }
    // Step 3 : return head
    head = prev;
    return head;
}