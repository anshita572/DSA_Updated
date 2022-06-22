//https://bit.ly/3srTkOv
//TC : O(n)
#include<stack>
bool findRedundantBrackets(string &s)
{  stack<char>st;
    for(int i=0;i<s.length();i++)
	{
		char ch=s[i];
		if(ch=='(' || ch=='+' ||ch=='-'||ch=='*'||ch=='/')
		{
			st.push(ch);
		}
		else //if(ch=')' || ch=any lower case letter)//ignoring lower case letters
		{  if(ch==')')
		{bool redundant=true;
		 while(st.top()!='(')
		 { char top=st.top();
			if(top=='+'||top=='-'||top=='*'||top=='/')
			{
				 redundant=false;
				st.pop();
			}
		 }
			if(redundant==true)
			{
				return true;
			}
		 st.pop(); //popping'('
		}
		}
	}
		return false;	
}
