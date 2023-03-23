// https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    solve(root->left, count);
    solve(root->right, count);
}
int countLeaves(Node *root)
{
    int count = 0;
    solve(root, count);
    return count;
}