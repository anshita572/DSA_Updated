//https://leetcode.com/problems/detect-capital/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        int count=0;
        for(int i=0;i<word.size();i++)
        {if(word[i]>='A' && word[i]<='Z')
        {count++;}
        }
        if(count==0)
        {return true;}
       else if(count==word.size())
        {return true;}
        else if(count == 1 && word[0]>='A' && word[0]<='Z')
        {return true;}
        else
        {return false;}
    }
};