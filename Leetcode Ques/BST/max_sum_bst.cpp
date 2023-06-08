// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
// TC : O(n) SC : O(h)
class Info {
public:
    int sum;
    int mini;
    int maxi;
    // int size;
    bool isBST;
};

Info solve(TreeNode* root, int& maxSum) {
    if (root == NULL) {
        return {0, INT_MAX, INT_MIN, true};
    }

    Info left = solve(root->left, maxSum);
    Info right = solve(root->right, maxSum);

    Info currNode;
    currNode.sum = left.sum + right.sum + root->val;
    currNode.mini = min(root->val, min(left.mini, right.mini));
    currNode.maxi = max(root->val, max(left.maxi, right.maxi));
    // currNode.size = left.size + right.size + 1;
    
    if (left.isBST && right.isBST && root->val > left.maxi && root->val < right.mini) {
        currNode.isBST = true;
        maxSum = max(maxSum, currNode.sum);
    } else {
        currNode.isBST = false;
    }

    return currNode;
}
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        solve(root, maxSum);
        return maxSum;
    }
};