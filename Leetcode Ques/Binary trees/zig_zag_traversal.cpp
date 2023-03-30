//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

//TC : O(n)  SC:O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
         if(root == NULL)
         {return ans;}
         queue<TreeNode*>q;
         q.push(root);
         bool lr=true; //traversing left to right
         while(!q.empty())
         {
             int size=q.size();
             vector<int>level(size);
             for(int i=0;i<size;i++)
             {
             TreeNode*temp=q.front();
             q.pop();
             if(temp->left!=NULL)
             {q.push(temp->left);}
             if(temp->right!=NULL)
             {q.push(temp->right);}  
             if(lr==true)
             {level[i]=temp->val;}
             else //if (lr==false) => traversing right to left
             {level[size-1-i]=temp->val;}
             }
             lr=!lr; //if true then make it false,if false then make it true
             ans.push_back(level);
         }
         return ans;
    }
};