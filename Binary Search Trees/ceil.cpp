// https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0
// TC : O(h) SC : O(1)
int findCeil(BinaryTreeNode<int> *node, int x){
         int ceil=-1;
         while(node != NULL)
         { if(node->data == x)
         {ceil=node->data;
         return ceil;
         }
         else if(node->data > x)
         {
             ceil=node->data;
             node=node->left;
         }
         else //if(node->data < x)
         {node=node->right;}
         }
          return ceil;
}