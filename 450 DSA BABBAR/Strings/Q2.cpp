//https://practice.geeksforgeeks.org/problems/palindrome-string0817/1
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
	int isPalindrome(string S)
	{
	   int n=S.length();
	   int i=0;
	   int j=n-1;
	   while(i<=j)
	   {
	      if(S[i]==S[j])
	      {i++;
	       j--;
	      }
	      else
	      {return 0;}
	   }
	   return 1;
	}

};