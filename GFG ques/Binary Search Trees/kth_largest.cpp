//https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
//M1
class Solution
{
    public:
    void inorder(Node* root,vector<int>&ans)
    {if(root==NULL)
    {return;}
     inorder(root->left,ans);
     ans.push_back(root->data);
     inorder(root->right,ans);
    }
    int kthLargest(Node *root, int K)
    {vector<int>ans;
       inorder(root,ans); 
       int n=ans.size();
       return ans[n-K];
       
    }
};
// M2
class Solution
{
    public:
    int solve(Node*root,int &K)
    {if(root == NULL)
        {return -1;}
        int r=solve(root->right,K);
        if(r!=-1)
        {return r;}
        K--;
        if(K==0)
        {return root->data;}
        return solve(root->left,K);
    }
    int kthLargest(Node *root, int K)
    {
        return solve(root,K);
    }
};