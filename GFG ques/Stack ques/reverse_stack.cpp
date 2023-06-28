// https://practice.geeksforgeeks.org/problems/reverse-a-stack/1
// https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/
// TC : O(n^2) SC: O(n) (using recursion)
// can be optimized using a queue to TC: O(n) (this approach is yet to be tried)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    void pushAtBottom(stack<int> &St,int temp)
    {if(St.empty())
    {   St.push(temp);
        return;}
        int num=St.top();
        St.pop();
        pushAtBottom(St,temp);
        St.push(num);
    }
    void solve(stack<int> &St)
    {if(St.empty())
    {return;}
    int temp=St.top();
    St.pop();
    solve(St);
    pushAtBottom(St,temp);
    }
    void Reverse(stack<int> &St){
        solve(St);
    }
};