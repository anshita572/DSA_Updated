//https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1/#

//TC : O(n)
//SC : O(n)

class Solution{
    public:
    
    vector <int> zigZagTraversal(Node* root)
    {
    		stack<Node*>s1;
    	stack<Node*>s2;
    	s1.push(root);
    	vector <int>ans;
    	while(!s1.empty() || !s2.empty())
    	{
    	   while(!s1.empty())
    	   {
    	    Node* temp=s1.top();
    	    s1.pop();
    	    ans.push_back(temp->data);
    	    if(temp->left)   //left to right
    	    {
    	        s2.push(temp->left); //First push left child in s2
    	    }
    	     if(temp->right)
    	    {
    	        s2.push(temp->right);//Then push right child in s2
    	    }
    	
    	  }
    	  while(!s2.empty())
    	  {
    	      Node* temp=s2.top();
    	    s2.pop();
    	    ans.push_back(temp->data);
    	                              //right to left
    	     if(temp->right)
    	    {
    	        s1.push(temp->right); //First push right child in s1
    	    }
    	    if(temp->left)
    	    {
    	        s1.push(temp->left);//Then push left child in s1
    	    }
    	  }
    	}
    	return ans;
    }
};