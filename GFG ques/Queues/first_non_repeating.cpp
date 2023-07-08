// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
// TC:O(n) SC:O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char,int>mp;
		    queue<char>q;
		    string ans;
		    int n=A.size();
		    for(int i=0;i<n;i++)
		    {char ch=A[i];
		     q.push(ch);
		     mp[ch]++;
		     while(!q.empty())
		     {if(mp[q.front()]>1)
		      {q.pop();}
		      else
		      {ans.push_back(q.front());
		       break;
		      }
		         
		     }
		     if(q.empty())
		     {ans.push_back('#');}
		    }
		    return ans;
		}

};