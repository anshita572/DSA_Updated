#include<iostream>
using namespace std;
class node{
public:
int data;
node *next;//Pointer of node type
node(int data) //Parameterised constructor
{
    this->data=data;
    this->next=NULL;
}
};
void insertAtHead(node* &head,int d) //d is data
{
    node *temp=new node(d);//dynamic allocation
    temp->next=head; //head has address of node1 and now temp will store that address
    head=temp;//ab head will store address of temp (temp will be the first node after inserting)

}
void printNode(node* &head)
{node*temp=head;
while(temp!=NULL) //loop until temp reaches the last node and points to NULL
{
    cout<<temp->data<<" ";//printing data of node to which temp is pointing
    temp=temp->next;//updating temp(like temp++)
}
cout<<endl;
}
int main(){
node *node1=new node(10);
node*head=node1;
printNode(head);
insertAtHead(head,12);
printNode(head);
insertAtHead(head,15);
printNode(head);

return 0;
}