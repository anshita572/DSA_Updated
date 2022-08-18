//https://leetcode.com/problems/rotate-string/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//TC :O(n^2) ,SC:O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
        {return false;}
        if(s.compare(goal)==0)
        {return true;}
        int partition=1;
        for(int i=partition;i<s.length();i++)
        {//s.substr(start_position,length of substring)
            string X=s.substr(0,partition);//a
            string val=s.substr(partition,s.length());//bcde
            val=val+X;//bcde + a = bcdea
            if(val.compare(goal)==0)
            {return true;}
            else
            {partition++;}
        }
        return false;
    }
};