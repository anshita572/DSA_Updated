// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
// TC : O(n) SC : O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
       vector<int>ans;
       for(int i = 0; i < n; i++){
           int index = abs(arr[i]) - 1;
           if(arr[index] < 0){
               ans.push_back(abs(arr[i]));
           }
           else{
           arr[index] = -arr[index];
           }
       }
       for(int i = 0; i < n; i++){
           if (arr[i] > 0){
               ans.push_back(i+1);
               break;
           }
       }
       return ans;
    }
};