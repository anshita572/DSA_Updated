//https://leetcode.com/problems/linked-list-cycle-ii/
//TC :O(n)
//SC :O(1)
#include <iostream>
#include <vector>
using namespace std;
// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public: //Floyd detection
    ListNode* hasCycle(ListNode *head) {
        //empty LL or LL having 1 node
        if(head==NULL || head->next==NULL)
        {return NULL;}
       //if we don't include case of LL having 1 node then slow==fast and it will return true
        ListNode *slow=head;
        ListNode *fast=head;
        while(slow!=NULL && fast!=NULL)
        { 
         fast=fast->next;//1st step
         if(fast!=NULL)
         {fast=fast->next;}//2nd step
         slow=slow->next;//one step
         if(slow==fast)
         {return fast;} //or return slow as fast and slow both at same postion
        }
        return NULL; //no cycle found 
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=hasCycle(head); //fast basically is the intersection of fast and slow
        ListNode*slow=head;
        if(fast==NULL)//if no cycle was found
        {return NULL;}
        while(slow!=fast)
        {
            slow=slow->next;//one step
            fast=fast->next;//one step
        }
        return slow;  //or return fast as both at same position
    }
};