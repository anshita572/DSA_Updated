//https://practice.geeksforgeeks.org/problems/lucky-alive-person-in-a-circle1229/1

//exactly same as circular game/josephus problem with k=2 as fixed always
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
int solve(int N)
    {
        if(N==1)
        {return 0;}
        return (solve(N-1)+2)%N;  //k=2 in winner of circular game/Josphesus problem
    }
    int find(int N){
       int ans=solve(N)+1;
        return ans;
    }
};