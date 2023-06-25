// https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1
// TC : O(N) , SC : O(N)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// M1 : recursive approach
class Solution
{
    public:
    void solve(stack<int>&s,int count,int mid)
    {if(count == mid)
        {s.pop();
         return;
        }
        int top=s.top();
        s.pop();
        solve(s,count+1,mid);
        s.push(top);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {   int mid=sizeOfStack/2;
        int count=0;
        solve(s,count,mid);
    }
};

// M2 : iterative approach
class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {int count=0;
     stack<int>s2;
     while(count != sizeOfStack/2)
     {s2.push(s.top());
      s.pop();
      count++;
     }
     s.pop();
     while(!s2.empty())
     {s.push(s2.top());
      s2.pop();
     }
    }
};