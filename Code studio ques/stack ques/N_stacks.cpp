// https://www.codingninjas.com/studio/problems/n-stacks-in-an-array_1164271?leftPanelTab=0
// https://takeuforward.org/data-structure/implement-k-stacks-in-a-single-array/
// TC:O(1) SC:O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class NStack
{ int *arr;
  int *top;
  int *next;
  int n;
  int s;
  int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    { n=N;
      s=S;
      arr=new int[s];
      top=new int[n];
      next=new int[s];
    //   initialise top array with -1
      for(int i=0;i<n;i++)
      {top[i]=-1;}
    //   initialise next array
      for(int i=0;i<s;i++)
      {next[i]=i+1;}
    //   initialise last value with -1
      next[s-1]=-1;
      freespot=0;
      
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
    //    check for overflow
        if(freespot==-1)
        {return false;}
        // find index where x is to be inserted
        int index=freespot;
        // update freespot
        freespot=next[index];
        // insert x into array
        arr[index]=x;
        // update next
        next[index]=top[m-1];
        // update top
        top[m-1]=index;
        return true;

    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    { if(top[m-1]==-1)
      {return -1;}
    //   find index of element to be popped
      int index=top[m-1];
    //   find new top index
      top[m-1]=next[index];
      next[index]=freespot;
      freespot=index;
      return arr[index];
       
    }
};