// https://leetcode.com/problems/merge-k-sorted-lists/description/
// TC : O(n*k log k) , SC : O(k)
class compare{
 public:
    bool operator()(ListNode* a,ListNode* b)
     {return a->val > b->val;}
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        int k=lists.size();
        if(k==0)
        {return NULL;}
        //step 1 : push 1st element of all linked lists into min heap
        for(int i=0;i<k;i++)
        {if(lists[i]!=NULL)
        {pq.push(lists[i]);}
        }
        ListNode*head=NULL;
        ListNode*tail=NULL;
        while(!pq.empty())
        {ListNode*temp=pq.top();
         pq.pop();
         //temp(min among 1st element of all LL),when we pop top,we push 2nd element of that particular LL 
         if(temp->next != NULL)
         {pq.push(temp->next);}
         if(head == NULL)
         {//initially,when we pop for the 1st time then answer LL is empty
          head=temp;
         tail=temp;}
         else
         {// when we pop for 2nd,3rd....till while loop runs
           tail->next=temp;
           tail=tail->next;
         }
        }
        return head;
    }
};