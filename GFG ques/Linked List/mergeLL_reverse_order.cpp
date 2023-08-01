// https://practice.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1
// TC: O(n+m) SC: O(1)
struct Node * reverseLL(Node *head)
{ Node *curr = head;
  Node * prev = NULL;
  Node *temp = NULL;
  while (curr != NULL){
      temp=curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
  }
    return prev;
}
struct Node* merge(Node* list1,Node* list2)
    {if(list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list1;
    }
      Node*ans =new Node; //dummy node
      ans->data=-1;
      ans->next =NULL;
     Node* temp = ans;
     while (list1 != NULL && list2 != NULL){
     if(list1->data < list2->data){
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

struct Node * mergeResult(Node *node1,Node *node2)
{struct Node *ans = merge(node1, node2);
 return reverseLL(ans);
  
}