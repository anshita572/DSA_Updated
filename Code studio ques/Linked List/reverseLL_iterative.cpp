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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    if (head == NULL || head->next == NULL) // if LL is empty or single element is present
    {
        return head;
    }
    while (curr != NULL)
    {
        LinkedListNode<int> *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        // cant'do  curr=curr->next; as curr ka next hamne prev ko point krwa diya h
    }
    head = prev;
    return head;
}