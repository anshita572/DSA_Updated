// https://leetcode.com/problems/reverse-linked-list/
// TC: O(N) SC: O(n) (Recursive)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {return head;}
        ListNode* solve=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return solve;
    }
};
