// https://www.codingninjas.com/studio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?topList=love-babbar-dsa-sheet-problems%3Fsource%3Dyoutube&campaign=Codestudio_Lovebabbar&utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Lovebabbar&leftPanelTab=0

// TC:O(1) SC:O(1) (excluding stack space)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#include<stack>
class SpecialStack {
    public:
    stack<int>s;
    int mini;   
    void push(int data) {
     if(s.empty())
     {s.push(data);
      mini=data;}
    else
    {
        if(data < mini)
        {s.push(2*data-mini);
        mini=data;}
        else
        {s.push(data);}
    }   
    }

    int pop() {
        // Implement the pop() function.
        if(s.empty())
        {return -1;}
        int curr=s.top();
        s.pop();
        if (curr > mini)
        {return curr;}
        else
        {int prevMin=mini;
         int val=2*mini-curr;
         mini=val;
         return prevMin;}
    }

    int top() {
       if(s.empty())
       {return -1;}
       int curr=s.top();
       if(curr<mini)
       {return mini;}
       return curr;
    }

    bool isEmpty() {
      return s.empty();
    }

    int getMin() {
        if(s.empty())
       {return -1;}
       return mini;
    }  
};