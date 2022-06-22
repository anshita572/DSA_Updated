// https://bit.ly/3rSdTDo
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

Node *hasCycle(Node *head)
{ // to detect cycle
    // empty LL or LL having 1 node
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    // if we don't include case of LL having 1 node then slow==fast and it will return true
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next; // 1st step
        if (fast != NULL)
        {
            fast = fast->next;
        }                  // 2nd step
        slow = slow->next; // one step
        if (slow == fast)
        {
            return fast;
        } // or return slow as fast and slow both at same postion
    }
    return NULL; // no cycle found
}
Node *detectCycle(Node *head)
{                                // to find beginning node of cycle
    Node *fast = hasCycle(head); // fast basically is the intersection of fast and slow
    Node *slow = head;
    if (fast == NULL) // if no cycle was found
    {
        return NULL;
    }
    while (slow != fast)
    {
        slow = slow->next; // one step
        fast = fast->next; // one step
    }
    return slow; // or return fast as both at same position
}
Node *removeLoop(Node *head)
{
    Node *startOfLoop = detectCycle(head);
    if (startOfLoop == NULL)
    {
        return head;
    }
    Node *temp = startOfLoop;
    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}