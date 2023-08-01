// https://leetcode.com/problems/palindrome-linked-list/description/
// TC: O(n) SC: O(1)
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
    ListNode *getMid(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        while (fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
         return true;
        }
        ListNode *mid = getMid(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;
        right = reverseLL(right);
        while(left != NULL && right != NULL){
            if(left -> val == right->val){
                left = left->next;
                right = right->next;
            }
            else
            {return false;}
        }
        return true;
    }
};