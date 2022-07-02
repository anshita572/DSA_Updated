//https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#
//TC :O(n)
//SC :O(height)
class Solution
{
public:
   void solve(Node *root,int sum,int len,int &maxSum,int &maxLen)
   {
       if(root == NULL)
       {
          if(len > maxLen)
          { maxLen=len;
              maxSum=sum;
          }
          if(len == maxLen)
          {
              maxSum = max(sum,maxSum);
          }
           return;
       }
    //   if(root->left == NULL && root->right == NULL)
    //   {
    //       if(len > maxLen)
    //       { maxLen=len;
    //           maxSum=sum;
    //       }
    //       if(len == maxLen)
    //       {
    //           maxSum = max(sum,maxSum);
    //       }
    //       return;
    //   }
       sum = sum + root->data;
       solve(root->left,sum,len+1,maxSum,maxLen);
       solve(root->right,sum,len+1,maxSum,maxLen);
   }
    
    int sumOfLongRootToLeafPath(Node *root)
    {  int sum=0;
    int maxSum = INT_MIN;
    int len=0;
    int maxLen=0;
       solve(root,sum,len,maxSum,maxLen);
       return maxSum;
    }
};
