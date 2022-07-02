//https://practice.geeksforgeeks.org/problems/k-sum-paths/1/#

class Solution{
  public:
    void solve(Node *root,int k,int &count,vector<int>path)
    {
        if(root == NULL)
        {return;}
        path.push_back(root->data);
        solve(root->left,k,count,path);
        solve(root->right,k,count,path);
       long long int sum=0;
        for(int i=path.size()-1;i>=0;i--)
        {
            sum=sum+path[i];
            if(sum==k)
            {count++;}
        }
    }
    int sumK(Node *root,int k)
    {
       vector<int>path;
    
     int count=0;
       solve(root,k,count,path);
       return count;
       
    }
};