//https://leetcode.com/problems/detect-capital/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;//count of capital letters
        for(int i=0;i<word.size();i++)
        {if(word[i]>='A' && word[i]<='Z')
        {count++;}
        }
        if(count==0)  //=> all small letters
        {return true;}
       else if(count==word.size())  // => all capital letters
        {return true;}
        else if(count == 1 && word[0]>='A' && word[0]<='Z')//=> 1st capital ,other letters small
        {return true;}
        else
        {return false;}
    }
};