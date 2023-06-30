#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// with the same approach as celebrity stack problem
// TC:O(n) SC:O(n)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>M(n+1,vector<int>(n+1));
        for(int i=0;i<trust.size();i++)
        {M[trust[i][0]][trust[i][1]]=1;}
        stack<int>s;
        for(int i=1;i<=n;i++)
        {s.push(i);}
        while(s.size() != 1)
        {int a=s.top();
         s.pop();
         int b=s.top();
         s.pop();
         if(M[a][b]==1)
         {s.push(b);}
         else
         {s.push(a);}
        }
        int candidate = s.top();
        int zeroCount=0;
        for(int i=1;i<=n;i++)
        {if(M[candidate][i] == 0)
        {zeroCount++;}
        }
        if(zeroCount != n)
        {return -1;}
        
        int oneCount=0;
        for(int i=1;i<=n;i++)
        {if(M[i][candidate] == 1)
        {oneCount++;}
        }
        if(oneCount != n-1)
        {return -1;}
        return candidate;
    }
};