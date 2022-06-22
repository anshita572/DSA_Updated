// https://bit.ly/3tRF3ga

//   Following is the class structure of the Node class:
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

Node *getMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if (head->next->next == NULL)
    {
        return head->next;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        slow = slow->next; // one step
        fast = fast->next; // 1st step
        if (fast != NULL)
        {
            fast = fast->next; // 2nd step
        }
    }
    return slow;
}
Node *findMiddle(Node *head)
{
    Node *ans = getMiddle(head);
    return ans;
}