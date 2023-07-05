// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
// M1 : Using recursion
// TC:O(n) SC:O(k)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(queue<int>&q, int k,int n)
{if(q.size()==n-k)
 {return;}
 int element=q.front();
 q.pop();
 solve(q,k,n);
 q.push(element);
    
}
queue<int> modifyQueue(queue<int> q, int k) {
    int n=q.size();
    solve(q,k,n);
    for(int i=0;i<n-k;i++)
    {int element=q.front();
     q.pop();
     q.push(element);
    }
    return q;
   
}
// M2 : Using stack
// TC:O(n) SC:O(k)
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int>s;
    //push first k elements in stack
    for(int i=0;i<k;i++)
    {
        int element=q.front();
        q.pop();
        s.push(element);
    }
    //pop from stack and add in queue (reveresed k elements)
    while(!s.empty())
    {
        int element=s.top();
        s.pop();
        q.push(element);
    }
    int i=q.size()-k;
    while(i--) //n-k elements pop from q and then add in q so that n-k elements end m aa jaaye
    {
        int element=q.front();
        q.pop();
        q.push(element);
    }
    return q;
}