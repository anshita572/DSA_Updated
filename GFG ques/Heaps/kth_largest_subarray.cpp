// https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1
// M1 : Iterative
// TC : O(N^2 log(N^2)) , SC : O(N)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        vector<int>sumArray;
        for(int i=0;i<N;i++)
        {int sum=0;
        for(int j=i;j<N;j++)
        {sum+=Arr[j];
        sumArray.push_back(sum);
        }
        }
        sort(sumArray.begin(),sumArray.end());
        int size=sumArray.size();
        return sumArray[size-K];
    }
};
// M2 : Using Min Heap
// TC : O(N^2 log(K)) , SC : O(K)
class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<N;i++)
        {int sum=0;
         for(int j=i;j<N;j++)
        {sum+=Arr[j];
         if(pq.size()<K) 
         {pq.push(sum);}
         else // if k elements have been pushed
         {if(sum>pq.top()) //push sum only if gretaer than top element of min heap
          {pq.pop();
           pq.push(sum);
          }
             
         }
        }
         
            
        }
        return pq.top();
    }
};