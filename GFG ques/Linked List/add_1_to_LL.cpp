// https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
// TC: O(n) SC: O(1)
class Solution
{
    public:
    Node *reverseLL(Node *head){
        Node *curr = head;
        Node *temp = NULL;
        Node * prev = NULL;
        while (curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
     Node *temp = reverseLL(head);
     Node * newHead = temp;
     int carry = 0;
     int sum = carry + 1 + temp->data;
     int digit = sum%10;
     temp->data = digit;
     carry = sum/10;
     // eg 91 , we will have a carry 
     // if you do temp != NULL then in case of 99 , when we need to
     // create a new node to store 1 , it will give runtime error as
     // by end of loop temp is NULL , so make sure by the end of this
     // loop , we are at last node i.e.0 in this case
     while(carry != NULL && temp->next != NULL){
         temp = temp->next;
         int sum = carry + temp->data;
         int digit = sum%10;
         temp->data = digit;
         carry = sum/10;
     }
     if(carry != NULL){
         Node *last = new Node(carry);
        //  last->data = carry;
         last->next = NULL;
         temp->next = last;
         temp = last;
     }
      temp = newHead;
      temp = reverseLL(temp);
      return temp;
    }
};