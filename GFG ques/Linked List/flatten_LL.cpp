// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
// Read detailed explanation :https://www.codingninjas.com/studio/library/flatten-a-linked-list
// TC:O(n*n*m) SC:O(n*m) (due to recursion stack)
Node *merge(Node *list1,Node *list2)
{if(list1 == NULL)
 {return list2;}
 if(list2 == NULL)
 {return list1;}
 Node *ans = new Node(-1);
 Node * temp = ans;
 while(list1 != NULL && list2 != NULL){
     if (list1->data < list2->data){
         temp->bottom = list1;
         temp = list1;
         list1 = list1->bottom;
     }
     else{
         temp->bottom = list2;
         temp = list2;
         list2 = list2->bottom;
     }
 }
 while(list1 != NULL){
     temp->bottom = list1;
     temp = list1;
     list1 = list1->bottom;
 }
 while(list2 != NULL){
     temp->bottom = list2;
     temp = list2;
     list2 = list2->bottom;
 }
 ans = ans->bottom;
 return ans;
    
}
Node *flatten(Node *root)
{
  if(root == NULL || root->next == NULL)
  {return root;}
  root->next = flatten(root->next);
  root = merge(root,root->next);
  return root;
}

