// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// TC:O(n) SC:O(k)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
            queue<long long>q;
            vector<long long>ans;
            //process first window
            for(int i=0;i<K;i++)
            {
                if(A[i]<0) //if negative element in array
                {
                    q.push(i);//push index of that negative element
                }
            }
            if(q.size()>0) //if size of q>0 ,push that value in ans
            {
                ans.push_back(A[q.front()]);
            }
            else
            {ans.push_back(0);}
            
            //process remaining windows
            for(int i=K;i<N;i++)
            {
               if((i-q.front()>=K) && !q.empty())
               {q.pop();}//pop that element at front if window size exceeds
               if(A[i]<0) //if negative element in array
                {
                    q.push(i);//push index of that negative element
                }
             if(q.size()>0) 
            {
                ans.push_back(A[q.front()]);
            }
            else
            {ans.push_back(0);}
            }
           
            return ans;
            
 }