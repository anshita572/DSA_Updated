// https://www.codingninjas.com/codestudio/problems/h_920474?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// TC
void inorder(TreeNode<int> *root,vector<int>&ans)
    {
        if(root == NULL)
        {return;}
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
vector<int> mergeArray(vector<int>&ans1,vector<int>&ans2)
    {
        vector<int>arr(ans1.size()+ans2.size());
        int i=0;
        int j=0;
        int k=0;
        if(ans1.size()==0)
        {return ans2;}
        if(ans2.size()==0)
        {return ans1;}
        while(i < ans1.size() && j < ans2.size())
        {
            if(ans1[i]<ans2[j])
            {arr[k++]=ans1[i++];}
            else
            {arr[k++]=ans2[j++];}
        }
        while(i < ans1.size())
        {arr[k++]=ans1[i++];}
        while(j < ans2.size())
        {arr[k++]=ans2[j++];}
        return arr;
    }
    TreeNode<int> *toBst(vector<int>merge,int s,int e)
    {
        if(s > e)
        {return NULL;}
        int mid = (e-s)+s/2;
        TreeNode<int>*root = new TreeNode<int>(merge[mid]);
        root->left=toBst(merge,s,mid-1);
        root->right=toBst(merge,mid+1,e);
        return root;
    }
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int>ans1;
       vector<int>ans2;
       inorder(root1,ans1);
       inorder(root2,ans2);
       vector<int>merge= mergeArray(ans1,ans2);
       int s=0;
       int e=merge.size()-1;
       return toBst(merge,s,e);
}