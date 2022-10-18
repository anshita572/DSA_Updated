//TLE with recursion (TC : 2^n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& slices,int s,int e,int mySlice)
    {
        if(mySlice==0 || s>e) //I have eaten all my slices or s>e
        {return 0;}
        int include=slices[s]+solve(slices,s+2,e,mySlice-1);
        int exclude=0+solve(slices,s+1,e,mySlice);
        return max(include,exclude);
    }
    int maxSizeSlices(vector<int>& slices) {
        int totalSlices=slices.size();
    int option1=solve(slices,0,slices.size()-2,totalSlices/3);//including first slice ,excluding last slice
    int option2=solve(slices,1,slices.size()-1,totalSlices/3);
      //  cout<<option1;
        return max(option1,option2);//excluding first slice,including last slice
        
    }
};