// https://leetcode.com/problems/add-two-numbers-ii/description/
// TC: O(max(m+n)) SC: O(max(m,n))
class Solution {
public:
    ListNode *reverseLL(ListNode *head){
        ListNode *curr = head;
        ListNode *temp = NULL;
        ListNode * prev = NULL;
        while (curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void insertAtTail(int digit, ListNode* &ansHead, ListNode* &ansTail){
        ListNode* temp = new ListNode(digit);
        if(ansHead == NULL){
            ansHead = temp;
            ansTail = temp;
        }
        else{
            ansTail->next = temp;
            ansTail = temp;
        }
    } 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       l1 = reverseLL(l1);
       l2 = reverseLL(l2);
       int carry = 0;
       ListNode* ansHead = NULL;
       ListNode* ansTail = NULL;
       while ( l1 != NULL && l2 != NULL){
           int sum = carry + l1->val + l2->val;
           int digit = sum%10;
           insertAtTail(digit,ansHead,ansTail);
           carry = sum/10;
           l1 = l1->next;
           l2 = l2->next;
       }
       while(l1 != NULL){
           int sum = carry + l1->val;
           int digit = sum%10;
           insertAtTail(digit,ansHead,ansTail);
           carry = sum/10;
           l1 = l1->next;
       }
       while(l2 != NULL){
           int sum = carry + l2->val;
           int digit = sum%10;
           insertAtTail(digit,ansHead,ansTail);
           carry = sum/10;
           l2 = l2->next;
       }
      if(carry != NULL){
           int sum = carry;
           int digit = sum%10;
           insertAtTail(digit,ansHead,ansTail);
           carry = sum/10;
       }
       ansHead = reverseLL(ansHead);
       return ansHead; 
    }
};