// https://leetcode.com/problems/merge-two-sorted-lists/
// TC: O(n+m) SC: O(1)
class Solution {
public:
    ListNode* merge(ListNode* list1,ListNode* list2)
    {if(list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list1;
    }
     ListNode*ans =new ListNode(-1); //dummy node
     ListNode* temp = ans;
     while (list1 != NULL && list2 != NULL){
     if(list1->val < list2->val){
         temp->next = list1;
         temp = list1;
         list1 = list1->next;
     }
     else{
         temp->next = list2;
         temp = list2;
         list2 = list2->next;
     }
    }
    while(list1 != NULL){
        temp->next = list1;
        temp = list1;
        list1 = list1->next;
    }
    while(list2 != NULL){
      temp->next = list2;
      temp = list2;
      list2 = list2->next;  
    }
        ans = ans->next;
        return ans;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode*  list2) {
         return merge(list1, list2);
    }
};