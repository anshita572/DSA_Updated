class Solution {
public:
    void all_traversals(TreeNode* root) {
        vector<int>preorder;
        vector<int>postorder;
        vector<int>inorder;
        stack<pair<TreeNode*,int>>st;
        st.push({root,1});
        while(!st.empty())
        {auto it=st.top();
        st.pop();
        if(it.second==1)
        {preorder.push_back(it.first->val);
        it.second++;
        st.push(it);
        if(it.first->left!=NULL)
        {st.push({it.first->left,1});}
        }
        else if(it.second==2)
        {
            inorder.push_back(it.first->data);
            if(it.first->right!=NULL)
            {st.push({it.first->right,1});}
        }
        else //if(it.second==3)
        {
            postorder.push_back(it.first->data);
        }

        }
        
};