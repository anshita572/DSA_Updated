//https://leetcode.com/problems/maximum-width-of-binary-tree/description/
//https://takeuforward.org/data-structure/maximum-width-of-a-binary-tree/
//TC : O(n) SC : O(n)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(root == NULL)
        {return ans;}
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int size=q.size();
            int mini=q.front().second;
            int first;
            int last;
            for(int i=0;i<size;i++)
            {long long curr_index = q.front().second - mini;
            TreeNode*temp = q.front().first;
             q.pop();
             if(i==0)
             {first = curr_index;}
             if(i==size-1)
             {last = curr_index;}
             if(temp->left)
             {q.push({temp->left,2*curr_index+1});}
             if(temp->right)
             {q.push({temp->right,2*curr_index+2});}
            }
            ans = max(ans,last-first+1);
        }
      return ans;
    }
};