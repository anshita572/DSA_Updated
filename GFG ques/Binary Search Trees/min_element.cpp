//https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1
int minValue(Node* root) {
    Node*temp=root;
    if(temp==NULL) //if empty tree
    {return -1;}
    while(temp->left!=NULL)
    {temp=temp->left;}
    int val=temp->data;
    return val;
}