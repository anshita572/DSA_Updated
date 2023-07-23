// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
        {return NULL;}
         ListNode* curr = head->next;
         ListNode* prev = head;
         while(curr != NULL)
         {if(prev->val == curr->val)
          {prev->next = curr->next;
           curr->next = NULL;
        //    delete(curr->next);
            curr = prev->next;
// not updating prev as there can be multiple duplicates
          }
          else
          {prev = curr;
           curr = curr->next;}

         }
         return head;
    }
};