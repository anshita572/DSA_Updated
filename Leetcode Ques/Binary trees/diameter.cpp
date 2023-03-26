//https://leetcode.com/problems/diameter-of-binary-tree/description/
//TC : O(n)

// In the findHeight function, the maxi variable should be initialized to the maximum value of findHeight(root->left, maxi) and findHeight(root->right, maxi). This is to ensure that the maximum diameter of the binary tree is considered, even if it is not passing through the root node.
class Solution {
public:
    int findHeight(TreeNode* root, int& maxi) {
    if (root == NULL) {
        return 0;
    }
    int lh = findHeight(root->left, maxi);
    int rh = findHeight(root->right, maxi);
    maxi = max(maxi, lh + rh);
    return 1 + max(lh, rh);
}
int solve(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int maxi = INT_MIN;
    int lh = findHeight(root->left, maxi);
    int rh = findHeight(root->right, maxi);
    maxi = max(maxi, lh + rh);
    return maxi;
}
int diameterOfBinaryTree(TreeNode* root) {
  return solve(root);
}
};

