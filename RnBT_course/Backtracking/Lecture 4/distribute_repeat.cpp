//https://leetcode.com/problems/distribute-repeating-integers/
//TC :   SC :
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve( vector<int>& quantity, unordered_map<int,int>&mp,int index)
    {//base case
        if(index==quantity.size())
    {return true;}
    
    for(auto i:mp)
    {
        if(i.second>=quantity[index])
        {    
            // i.second=i.second-quantity[index];
             mp[i.first]=mp[i.first]-quantity[index];
            bool recursiveAns=solve(quantity,mp,index+1);//recursive call
        if(recursiveAns)
        {return true;}
        // i.second=i.second+quantity[index];
         mp[i.first]=mp[i.first]+quantity[index];//backtracking
        }
    }
    return false;
}
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
         unordered_map<int,int>mp;
        //Store frequency of nums vector in map
        for(int i=0;i<nums.size();i++)
        {mp[nums[i]]++;}
        int index=0;
        //sort quantity vector
        sort(quantity.begin(),quantity.end(),greater<int>());
        bool ans= solve(quantity,mp,index);
        return ans;
    }
};