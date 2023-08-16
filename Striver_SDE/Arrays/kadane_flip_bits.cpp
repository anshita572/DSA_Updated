// https://practice.geeksforgeeks.org/problems/flip-bits0240/1
// TC : O(n) , SC : O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxOnes(int a[], int n)
    { int count1 = 0;
      int sum = 0;
      int maxi = 0; // maxi is not INT_MIN as for a case like :
      // [1,1,1,1] , maxi will be -1 and hence ans will be
    //  instead of 4 , so maxi = 0
      for(int i = 0; i < n; i++){
          if(a[i] == 1){
              count1++;
              a[i] = -1;
          }
          else // if(a[i] == 0)
          {a[i] = 1;}
      }
      
      for(int i = 0; i < n; i++){
          sum += a[i];
          maxi = max(sum,maxi);
          if(sum < 0){
              sum = 0;
          }
      }
    int ans = count1 + maxi;
    return ans;
        
    }
};