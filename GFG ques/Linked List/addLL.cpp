//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    Node*reverse(Node*head)
    {
        Node*prev=NULL;
        Node*curr=head;
        Node*forward=NULL;
        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            
        }
        
        return prev;
    }
    void insertAtTail(struct Node* &head, struct Node* &tail,int data)
    {
        Node*temp=new Node(data);
        if(head==NULL) //empty LL
        {
            head=temp;
            tail=temp;
            return;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    Node*add(struct Node* first, struct Node* second)
    {  int carry=0;
    Node*ansHead=NULL;
    Node *ansTail=NULL;
        while(first!=NULL || second !=NULL || carry!=0)
        //for all cases like first LL is longer than second and vice versa or carry 
        //is remaining at end
        {
            int val1=0;
            if(first!=NULL)
            {val1=first->data;}
            int val2=0;
            if(second!=NULL)
            {val2=second->data;}
            int sum=carry+val1+val2;
            int digit=sum % 10;
            carry=sum / 10;
            //create node for digit and insert in ans linked lits
            insertAtTail(ansHead,ansTail,digit);
            if(first!=NULL)
            {first=first->next;}
            if(second!=NULL)
            {second=second->next;}
        }
        return ansHead;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {//Step 1 : reverse both LL
       first=reverse(first);
       second=reverse(second);
       //Step 2 : add 
       Node *ans=add(first,second);
       //Step 3 : reverse ans
       ans=reverse(ans);
       return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends