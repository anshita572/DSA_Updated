//https://leetcode.com/problems/string-compression/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//TC : O(n)  SC:O(n)
class Solution {
public:
    int compress(vector<char>& s) {
        int i=0;
        int ans=0;
        int n=s.size();
        while(i<n)
        {
            int j=i+1;
            while(j < n && s[i]==s[j])
            {j++;}
            int count=j-i;
            s[ans]=s[i];
            ans++;
            if(count > 1)
            {
                string str=to_string(count);
                for(auto it : str)
                {
                    s[ans]=it;
                    ans++;
                }
               
            }
             i=j;
        }
        return ans;
    }
};
    