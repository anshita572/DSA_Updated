// https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
// TC : O(N) , SC : O(N)
class Solution {
  public:
   int countNodes(struct Node* root)
    {if(root==NULL)
    {return 0;}
    int ans=1+countNodes(root->left)+countNodes(root->right);
    return ans;
    }
    bool isCBT(struct Node* root,int i,int count)
    {if(root==NULL)
     {return true;}
     if(i>=count)
     {return false;}
     else{
         bool left=isCBT(root->left,2*i+1,count);
         bool right=isCBT(root->right,2*i+2,count);
         return (left && right);
     }
    }
    bool isMaxHeap(struct Node* root)
    {
        if(root->left ==NULL && root->right==NULL)  //leaf node , then it is a heap
        {return true;}
        if(root->right == NULL) //only left child exists
        {if(root->data > root->left->data);
            {return true;}
        }
        else {
            bool left= isMaxHeap(root->left);
            bool right=isMaxHeap(root->right);
            if(left && right && root->data > root->left->data &&
            root->data > root->right->data)
            {return true;}
            else
            {return false;}
            // return (left && right && (root->data > root->left->data &&
            // root->data > root->right->data));
        }
    }
    bool isHeap(struct Node* tree) {
        int count=countNodes(tree);
        int i=0;
        if(isCBT(tree,i,count) && isMaxHeap(tree))
        {return true;}
        else
        {return false;}
    }
};