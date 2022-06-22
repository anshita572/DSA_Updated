//https://bit.ly/3rjMQC5 

//TC :O(n)
//SC :O(1)
#include <iostream>
using namespace std;

//    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    


Node * uniqueSortedList(Node * head) {
    if(head==NULL)
    {return NULL;}
    Node*curr=head;
    while(curr->next!=NULL)
    {
    if(curr->data != curr->next->data) //if not equal
    {
        curr=curr->next;
    }
    else{ //if equal
     delete (curr->next);
    curr->next=curr->next->next;
   // curr->next->next=NULL;
    
   }  
    }
     return head;
}
