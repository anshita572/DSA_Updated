//https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1/#
Node *ans(Node *root,int &k,int node)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == node)
    {
        return root;
    }
    Node *leftAns=ans(root->left,k,node);
    Node *rightAns=ans(root->right,k,node);
    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        if(k <=0)
        {
            k=INT_MAX; //so that k never gets close to 0
            return root;
        }
        return leftAns;
    }
    if(rightAns != NULL && leftAns == NULL)
    {
        k--;
        if(k <=0)
        {
            k=INT_MAX; //so that k never gets close to 0
            return root;
        }
        return rightAns;
    }
    return NULL;
    
}
int kthAncestor(Node *root, int k, int node)
{Node* sol=ans(root,k,node);
if(ans == NULL || sol->data ==node)
{return -1;}
else
{return sol->data;}
    
}
