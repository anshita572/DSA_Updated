//https://bit.ly/34kxPaq
//TC : O(n)
//SC : O(n)  (extra space of stack)
bool isValidParenthesis(string expression)
{
    stack<char>s;
	for(int i=0;i<expression.length();i++)
	{char ch=expression[i];
		if(ch=='{' ||ch=='('||
		 ch=='[')   ////if opening bracket, stack push
		{
			s.push(ch);
		}
		
	else 
	{if(!s.empty())  //if stack is not empty
		{char top=s.top();         
		if((top=='{' && ch=='}') ||
			(top=='(' && ch==')')||
		 (top=='[' && ch==']')) //opening and closing 
		//brackets match
	 {s.pop();}
	else  //opening and closing bracket does not match
	 {return false;}
	}  //closing bracket remaining but stack is empty
	 else 
	 {return false;}
	
 
}
}
	if(s.empty())   //if after whole for loop ends i.e.
	//expression ends if stack is empty=>balanced
	//els unbalanced
	{return true;}
	else
	{return false;}
}