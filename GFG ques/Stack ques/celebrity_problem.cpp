// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// M1 : brute force (TC : O(n^2) SC:O(1))
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
    bool knows(vector<vector<int> >& M,int i,int j)
    {if(M[i][j]==1)
    {return true;}
    return false;
        
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    { 
        for(int i=0;i<n;i++)
        {bool isCelebrity = true;
         for(int j=0;j<n;j++)
         {if(i!=j && (knows(M,i,j) || !knows(M,j,i)))
            {isCelebrity = false; // i is not a celebrity
             break;    
            }
             
         }
            if(isCelebrity)
            {return i;}
        }
       return -1;
    }
};
// M2 : (better)using stack (TC : O(n) SC:O(n))
class Solution 
{
    public:
    bool knows(vector<vector<int> >& M,int i,int j)
    {if(M[i][j]==1)
    {return true;}
    return false;
        
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    { 
        stack<int>s;
        for(int i=0;i<n;i++)
        {s.push(i);}
        while(s.size() != 1)
        {int a=s.top();
         s.pop();
         int b=s.top();
         s.pop();
         if(knows(M,a,b) && !knows(M,b,a))
         {s.push(b);}
         else
         {s.push(a);}
        }
        int candidate = s.top();
        int zeroCount=0;
        for(int i=0;i<n;i++)
        {if(M[candidate][i] == 0)
        {zeroCount++;}
        }
        if(zeroCount != n)
        {return -1;}
        
        int oneCount=0;
        for(int i=0;i<n;i++)
        {if(M[i][candidate] == 1)
        {oneCount++;}
        }
        if(oneCount != n-1)
        {return -1;}
        return candidate;
        
    }
};
// M3: optimal (TC : O(n) SC:O(1))
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int celebrity=0;
        for(int i=1;i<n;i++)
        {if(M[celebrity][i] == 1)
         {celebrity=i;}
        } 
        for(int i=0;i<n;i++)
        {if(M[celebrity][i] != 0)
            {return -1;}
         if(i!=celebrity && M[i][celebrity] !=1)
         {return -1;}
        }
        
        return celebrity;
    }
};