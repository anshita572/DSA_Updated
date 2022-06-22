// https://bit.ly/3s3fAOu
#include<iostream>
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


//Approach 2 : Data replacement not allowed(i.e.change links)
//Creating 3 separate LL and merging them
//TC : O(n)
//SC : O(1)
Node* insertAtTail(Node* &tail,Node* curr)
{
    tail->next=curr;
    //tail=tail->next; //OR tail = curr;  (updating tail)
     tail = curr;
}
Node* sortList(Node *head)
{
  Node*zeroHead=new Node(-1);
  Node *zeroTail=zeroHead;
  Node*oneHead=new Node(-1);
    Node *oneTail=oneHead;
  Node*twoHead=new Node(-1);
    Node *twoTail=twoHead;
    Node*curr=head;
    //creating 3 LL of zero's,one's,two's
    while(curr!=NULL)
    {
        if(curr->data==0)
        { insertAtTail(zeroTail,curr);}
         else if(curr->data==1)
        { insertAtTail(oneTail,curr);}
       else // if(curr->data==2)
        { insertAtTail(twoTail,curr);}
        curr=curr->next;
    }
    //merging 3 LL
    if(oneHead->next !=NULL) //1's list non-empty
    {
        zeroTail->next=oneHead->next;
    }
  else  //if(oneHead->next ==NULL)  //1's list empty
    {
        zeroTail->next=twoHead->next;
    }
   oneTail->next=twoHead->next;
    twoTail->next=NULL;
    //updating head
    head=zeroHead->next;
    //deleting dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}
