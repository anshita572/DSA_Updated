// https://leetcode.com/problems/reverse-nodes-in-k-group/description/
// Recursive Solution : TC: O(N) SC: O(N/K) 
// For each Linked List of size N, N/K or (N/K)+1 calls will be made during the recursion.
class Solution {
public:
    int getLength(ListNode* &head)
    {ListNode*temp=head;
     int length=0;
     while(temp != NULL){
         length++;
         temp=temp->next;
     }
        return length;
     }

    ListNode* reverse(ListNode* &head, int k,int length)
    {if(head == NULL || length < k)
     {return head;}
     ListNode* curr=head;
     ListNode* prev=NULL;
     ListNode* nex=NULL;
     int count=0;
     while(curr != NULL && count < k){
         nex=curr->next;
         curr->next=prev;
         prev=curr;
         curr=nex;
         count++;
     }
     if(nex != NULL)
     {head->next = reverse(nex,k,length-k);}
     return prev;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = getLength(head);
        return reverse(head,k,length);

    }
};