//Minimum bracket Reversal
//https://bit.ly/3GAYRr5
// M1: TC : O(n) SC:O(n)
#include<iostream>
using namespace std;
#include<stack>
int findMinimumCost(string str) {
//odd no.of brackets
	if((str.length()) % 2 !=0)
	   {
		   return -1;
	   }
	stack<char>s;
	for(int i=0;i<str.length();i++)
	{
		char ch=str[i];
		if(ch=='{')
		{s.push(ch);}
		else //if(ch=='}')
		{
			//2 cases
//1st case:corresponding '{' found i.e. valid string so remove i.e.pop
			if(!s.empty() && s.top()=='{')
			{s.pop();}
//2nd case : invalid string
			else
			{
				s.push(ch);
			}
		}
	}
	int a=0; //a=>count of close brackets
	int b=0;//b=>count of open brackets
	while(!s.empty())
	{
		if(s.top()=='}')
		{b++;}
		else //if(s.top()=='{')
		{a++;}
		s.pop();
	}
	int ans=(a+1)/2  + (b+1)/2; 
	// if a==0 and b==0 , it means that the string is already balanced
	// then ans =(0+1)/2 + (0+1)/2 = 0 (not 1 as (0+1)/2=0)
	return ans;
}

// M2 : TC : O(n) SC:O(1)
int countRev (string s)
{
    int n=s.size();
    if(n%2 == 1) 
    {return -1;}
    int open=0;
    int close=0;
    for(int i=0;i<n;i++)
    {if(s[i]=='{')
     {open++;}
     else //if(s[i]=='}'
       if(open==0)
       {close++;}
       else //if 1 match for open and close (decrease open)
       {open--;}
        
    }
    int count = (open+1)/2 + (close+1)/2;
    return count;
}
