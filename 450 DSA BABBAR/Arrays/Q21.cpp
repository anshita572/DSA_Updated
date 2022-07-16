//https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //TC :O(N)
    //SC:O(N) set is used
    bool subArrayExists(int arr[], int n)
    {
      int prefix_sum=0;
    set<int>s;
    for(int i=0;i<n;i++)
    {prefix_sum=prefix_sum+arr[i];
        if(prefix_sum==0)
        {return true;}
        if(s.count(prefix_sum)==1)
        {return true;}
        s.insert(prefix_sum);
    }
    return false;
    }
};
//Brute force 
//TC :O(N^2)
//SC:O(1)
//  bool subArrayExists(int arr[], int n)
//     {
//      for(int i=0;i<n;i++)
//      {int sum=0;
//          for(int j=i;j<n;j++)
//          {sum=sum+arr[j];
//              if(sum==0)
//              {return true;
//                  break;
//              }
//          }
//      }
//      return false;