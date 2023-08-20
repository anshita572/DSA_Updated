// https://practice.geeksforgeeks.org/problems/power-set4302/1#
// Time Complexity: O(2^n * n)
// Reason: O(2^n) for the outer for loop and O(n) for the inner for loop.
// Space Complexity: O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    int n = s.size();
		    int size = pow(2,n);
		    vector<string>ans;
		    for(int i = 0; i < size; i++){
		        string temp = "";
		        for(int j = 0; j < n; j++){
		            if(i & (1 << j)){
		                temp += s[j];
		            }
		        }
		        if(temp.size() > 0){
		            ans.push_back(temp);
		        }
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};