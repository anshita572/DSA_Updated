// https://www.codingninjas.com/codestudio/problems/_893049?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
   int pre=-1;
   int succ=-1;
   BinaryTreeNode<int>*temp=root;
   while(temp->data != key) //find the key
   {
       if(key < temp->data)
       {
           succ=temp->data;
           temp=temp->left;
       }
       else // if(key > temp->data)
       {
           pre = temp->data;
           temp=temp->right;
       }
   }
   //pre
   BinaryTreeNode<int>* leftTree = temp->left;
   while(leftTree != NULL)
   {pre=leftTree->data;
   leftTree=leftTree->right;} //since I want max value of leftTree,so move right
   //succ
   BinaryTreeNode<int>* rightTree=temp->right;
   while(rightTree!=NULL)
   {succ=rightTree->data;
   rightTree=rightTree->left;}
   pair<int,int>ans=make_pair(pre,succ);
   return ans;
}
