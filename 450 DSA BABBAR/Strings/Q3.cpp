//https://www.codingninjas.com/codestudio/problems/duplicate-characters_3189116?leftPanelTab=0
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
vector<pair<char,int>> duplicate_char(string s, int n){
  vector<pair<char,int>>ans;
   map<char,int>mp;
    for(int i=0;i<n;i++)
    {mp[s[i]]++;}
    for(auto it :mp)
    {
        if(it.second > 1)
        {ans.push_back(make_pair(it.first,it.second));}
    }
    return ans;
    //TC :O(n) , SC :O(1) constant space of 256
    //Doubt : Why size=256 ? 
    vector<pair<char,int>>ans;
    vector<int>freq(256);
    for(int i=0;i<n;i++)
    {freq[s[i]]++;}
    for(int i=0;i<256;i++)
    {if(freq[i]>1)
    {ans.push_back({char(i),freq[i]});}
    }
    return ans; 
}