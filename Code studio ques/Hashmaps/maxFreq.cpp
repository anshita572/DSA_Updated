//https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int maximumFrequency(vector<int> &arr, int n)
{
  unordered_map<int,int>m; //m.first stores arr numbers and 
    //m.second stores their count
     int maxFreq=INT_MIN;
     int ans=-1;
    for(int i=0;i<arr.size();i++)
    {
        m[arr[i]]++;
        maxFreq=max(maxFreq,m[arr[i]]);
        
    }
   for(int i=0;i<arr.size();i++)
   {if(maxFreq == m[arr[i]])
   {ans=arr[i];
   break;}
   }//so that in case of same max freq of 2numbers,the one with lower index is printed
    
//     for(auto i:m)
//     {
//         if(i.second > maxi)
//         {
//             maxi=i.second;
//             ans=i.first;
//         }
//     }
    return ans;
}