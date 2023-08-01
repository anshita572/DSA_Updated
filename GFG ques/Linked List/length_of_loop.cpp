// https://practice.geeksforgeeks.org/problems/find-length-of-loop/1
// TC: O(n) SC: O(1)
int countNodesinLoop(struct Node *head)
{  if(head == NULL || head->next == NULL){
    return 0;
}
   Node *fast = head;
   Node *slow = head;
   while (fast != NULL && fast->next != NULL){
       fast = fast->next->next;
       slow = slow->next;
       if(fast == slow)
       {break;}
   }
   if( fast != slow)
   {return 0;}
   int count = 1;
   while(slow->next != fast)
   {slow = slow->next;
    count++;   
   }
   return count;
   
}