// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode(0);
        dummy->next=curr;
       ListNode* prev = dummy;
       while(curr != NULL)
       { if(curr->next != NULL && 
       curr->val == curr->next->val)
       {while(curr->next != NULL && 
       curr->val == curr->next->val){
        curr = curr->next;}
        prev->next = curr->next;
       }
       else
       {prev = prev->next;}
       curr = curr->next;

       }
       return dummy->next;
    }
};