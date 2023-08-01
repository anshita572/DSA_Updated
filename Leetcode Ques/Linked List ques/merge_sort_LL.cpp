// https://leetcode.com/problems/sort-list/
// TC: O(nlogn) SC: O(1)
class Solution {
public:
    ListNode* findMiddle(ListNode* &head)
    {ListNode* fast = head->next;
     ListNode* slow = head;
     while(fast != NULL && fast->next != NULL)
     {fast =  fast->next->next;
      slow = slow->next;
      }
      return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right)
    {if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
     ListNode*ans =new ListNode(-1); //dummy node
     ListNode* temp = ans;
     while (left != NULL && right != NULL){
     if(left->val < right->val){
         temp->next = left;
         temp = left;
         left = left->next;
     }
     else{
         temp->next = right;
         temp = right;
         right = right->next;
     }
    }
    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right != NULL){
      temp->next = right;
      temp = right;
      right = right->next;  
    }
        ans = ans->next;
        return ans;
    }
    ListNode* mergeSort(ListNode* &head)
    { if(head == NULL || head->next == NULL)
      {return head;}
     ListNode* mid = findMiddle(head);
     ListNode* left = head;
     ListNode* right = mid->next;
     mid->next = NULL ; // so as to separate left and right
     left = mergeSort(left);
     right = mergeSort(right);
     ListNode* ans = merge(left,right);
     return ans;
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};