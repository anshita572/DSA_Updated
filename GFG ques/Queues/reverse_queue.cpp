// https://practice.geeksforgeeks.org/problems/queue-reversal/1
// M1 : Using stack
// TC:O(n) SC:O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int>s;
        while(!q.empty())
        {s.push(q.front());
         q.pop();
        }
        while(!s.empty())
        {q.push(s.top());
         s.pop();
        }
        return q;
    }
};
// M2 : Using recursion
// TC:O(n) SC:O(n)
class Solution
{
    public:
    void solve(queue<int>&q)
    {if(q.empty())
      {return;}
     int element=q.front();
     q.pop();
     solve(q);
     q.push(element);
    }
    queue<int> rev(queue<int> q)
    {solve(q);
     return q;
       
    }
};