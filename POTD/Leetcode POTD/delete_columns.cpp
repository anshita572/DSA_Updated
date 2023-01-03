//https://leetcode.com/problems/delete-columns-to-make-sorted/description/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int row=s.size();
        int col=s[0].size();
        int count=0;
        for(int j=0;j<col;j++)
        {for(int i=0;i<row-1;i++)
        {
            if(s[i][j]>s[i+1][j])
            {count++;
            break;}
        }}
        return count;
    }
};