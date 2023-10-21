//https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

// TC : O(n!*n*)  SC: O(n!*n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	void solve(int i,string &S,vector<string>&ans)
	{if(i>=S.size())
	    {ans.push_back(S);
	        return;
	    }
	    for(int j=i;j<S.size();j++)
	    { if(j>i&& S[j]==S[j-1])continue;  //to handle duplicates
	        swap(S[i],S[j]);
	        solve(i+1,S,ans);
	       swap(S[i],S[j]); //backtrack
	    }
	}
	
		vector<string>find_permutation(string S)
		{vector<string>ans;
		solve(0,S,ans);
		sort(ans.begin(),ans.end());
		return ans;
		    
		}
};