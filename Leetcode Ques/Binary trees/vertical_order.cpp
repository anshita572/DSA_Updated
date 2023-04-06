// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
// TC : O(n)  SC : O(n)
class Solution
{
public:
    vector<vector<int>> solve(TreeNode *root)
    {
        queue<pair<TreeNode *, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *temp = p.first;
            int vertical = p.second.first;
            int level = p.second.second;
            mp[vertical][level].insert(temp->val);
            if (temp->left != NULL)
            {
                q.push({temp->left, {vertical - 1, level + 1}});
            }
            if (temp->right != NULL)
            {
                q.push({temp->right, {vertical + 1, level + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto i : mp)
        {
            vector<int> col;
            for (auto j : i.second)
            {
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        return solve(root);
    }
};