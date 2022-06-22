//Minimum bracket Reversal
//https://bit.ly/3GAYRr5
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
	return ans;
}
