//https://bit.ly/3qY0KcF
//This code does not handle loops

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
bool isCircular(Node* head){
    //if LL is empty
    if(head==NULL)
    {
        return true;
    }
   //if LL is non-empty
    Node*temp=head;
    do{
        temp=temp->next;
    }
    while(temp!=NULL && temp!=head);
    if(temp==head)
    {return true;}
        else //if(temp==NULL)
        {return false;}
}
