// https://practice.geeksforgeeks.org/problems/search-a-node-in-bst/1
// M1 : recursive
//TC : O(h)  SC: O(h) (in case of balanced tree TC : O(log n))
bool search(Node* root, int x) {
    if(root==NULL)
    {return false;}
    if(x==root->data)
    {return true;}
    if(x > root->data)
    {return search(root->right,x);}
    else //if(x<root->val)
    {return search(root->left,x);}
    
}
// M2 : iterative
// TC : O(h)  SC: O(1) (in case of balanced tree TC : O(log n))
bool search(Node* root, int x) {
   Node*temp=root;
   while(temp!=NULL)
   {
       if(temp->data==x)
       {return true;}
       if(temp->data > x)
       {temp=temp->left;}
       else
       {temp=temp->right;}
       
   }
   return false;
}
