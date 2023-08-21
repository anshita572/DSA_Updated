// https://leetcode.com/problems/merge-intervals/description/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// M1 : Brute force , TC : O(n logn)+O(2n) , SC : O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(int i = 0; i < n; i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            if(!ans.empty() && e <= ans.back()[1]){ // already in interval
                continue;
            }
            for(int j = i+1; j < n; j++){
                if(e >= intervals[j][0]){
                     e = max(e,intervals[j][1]);
                }
                else{  // not overlapping, can't merge
                    break;
                }
            }
             ans.push_back({s,e});
        }
        return ans;   
    }
};
// M2 :Optimised , TC : O(n logn)+O(n) , SC : O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(int i = 0; i < n; i++){
            if(ans.empty() || ans.back()[1] < intervals[i][0]){
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
            else{
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }
            
        return ans;   
    }
};