//Floyd Cycle detection algo
// https://leetcode.com/problems/linked-list-cycle/
//TC :O(n)
//SC : O(1)
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
public:
    bool hasCycle(ListNode *head) {
        //empty LL or LL having 1 node
        if(head==NULL || head->next==NULL)
        {return false;}
       //if we don't include case of LL having 1 node then slow==fast and it will return true
        ListNode *slow=head;
        ListNode *fast=head;
        while(slow!=NULL && fast!=NULL)
        { 
         fast=fast->next;
         if(fast!=NULL)
         {fast=fast->next;}
         slow=slow->next;
         if(slow==fast)
         {return true;}
        }
        return false;
        
    }
};