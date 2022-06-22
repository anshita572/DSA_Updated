// https://bit.ly/3tRF3ga

// Following is the class structure of the Node class:
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

int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
Node *findMiddle(Node *head)
{
    int len = getLength(head);
    int ans = len / 2;
    int count = 0;
    Node *temp = head;
    while (count < ans)
    {
        temp = temp->next;
        count++;
    }
    return temp;
}