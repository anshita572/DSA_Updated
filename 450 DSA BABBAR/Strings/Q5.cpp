//https://leetcode.com/problems/rotate-string/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
// M1 : TC :O(n)  SC :O(n)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
        {return false;}
        if(s.compare(goal)==0)
        {return true;}
      queue<char>q1;
      queue<char>q2;
        for(int i=0;i<s.length();i++)
        {
            q1.push(s[i]);
            q2.push(goal[i]);
        }
        int count=0;
        while(count<goal.length()) //we don't to want to push and pop the same elements infintely ek hi baar krne h and in the worst case sbhi char ek baar push and pop honge i.e. keep popping q2‘s and pushing it back into it till the number of such operations are less than the size of the string
        {
            char frontCh=q2.front();
            q2.pop();
            q2.push(frontCh); //front ab dubara push ho k queue ki end m jaayega
            count++;
            if(q1==q2)
            {return true;}
        }
        return false;
    }
};

//M2 : TC :O(n^2) ,SC:O(1)
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