// https://leetcode.com/problems/linked-list-cycle/
//TC :O(n)
//SC : O(n)
#include <iostream>
#include <vector>
#include<map>
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
        if(head==NULL)
        {return false;}
        map<ListNode *,bool>visited;
        ListNode *temp=head;
        while(temp!=NULL)
        { //cycle is present
       if(visited[temp]==true)
       {return true;}
        
        visited[temp]=true;
        temp=temp->next;
        }
        
        return false;
        
        
    }
};