//https://bit.ly/34GjYL4
#include<iostream>
using namespace std;
#include<stack>
#include<vector>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{  
 vector<int>ans(n);
	stack<int>s;
	s.push(-1);
 for(int i=n-1;i>=0;i--)
 {
	int num=arr[i];
	//int top=s.top();
	 while(s.top() >= num)
	 {
		 s.pop();
	 }
	 ans[i]=s.top();
	 s.push(num);
 
 }
 return ans;
}
