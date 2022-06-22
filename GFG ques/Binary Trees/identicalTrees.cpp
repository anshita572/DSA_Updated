//https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1#
//TC :O(n)
//SC:O(height) ,max height can be n
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
       if(r1==NULL && r2==NULL)
       {
           return true;
       }
       if(r1==NULL && r2!=NULL)
       {
           return false;
       }
       if(r1!=NULL && r2==NULL)
       {
           return false;
       }
       
       //else if both roots are not NULL
       bool left=isIdentical(r1->left,r2->left);
       bool right=isIdentical(r1->right,r2->right);
       bool nodeValue=r1->data==r2->data;
       if(left && right && nodeValue)
       {
           return true;
       }
       else
       {
           return false;
       }
    }
};