//https://practice.geeksforgeeks.org/problems/even-and-odd/1
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void reArrange(int arr[], int N) {
        int i=0; //represents even position
        int j=1;//represents  odd position
        while(i<N && j<N)
        {
            if(arr[i]%2==0) //if even position has even no.
            {i=i+2;} //jump to next even position
            else if(arr[j]%2 !=0) //if odd position has odd no.
            {j=j+2;} //jump to next odd position
            else//if(arr[i]%2 !=0)
            {swap(arr[i],arr[j]);}
        }
    }
};