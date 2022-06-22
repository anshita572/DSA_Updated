// https://bit.ly/3H1lKov

//  Following is the class structure of the LinkedListNode class:
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void solve(LinkedListNode<int> *&head, LinkedListNode<int> *curr, LinkedListNode<int> *prev)
{
    // base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    LinkedListNode<int> *forward = curr->next;
    solve(head, forward, curr); // curr=forward,prev=curr;
    curr->next = prev;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = NULL;
    solve(head, curr, prev);
    return head;
}