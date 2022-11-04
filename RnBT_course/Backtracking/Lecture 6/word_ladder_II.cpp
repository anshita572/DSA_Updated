//https://leetcode.com/problems/word-ladder-ii/description/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//M1 : Backtracking (TLE)
class Solution {
public:
bool isConvertible(string a,string b)//function to check if possible to convert one string to another (only if difference==1)
{
    // if(a.length()!=b.length || a.length==0)
    // {return false;} //no need to apply these checks (see constraints of ques)
    int count=0;
    for(int i=0;i<a.length();i++)
    {if(a[i]!=b[i])
    {count++;}
    }
    if(count==1)
    {return true;}
    else
    {return false;}
}
int min(int a,int b)
{if(a<b)
{return a;}
else
{return b;}}
bool solve(string src,string dest,vector<string>&dict,map<string,bool>&visited,vector<string> &path ,vector<vector<string>>&ans,int &path_size)
{
    //base case
    if(dest.compare(path[path.size()-1])==0) //path's last string == dest
    {ans.push_back(path);
    path_size=min(path.size(),path_size);
    return true;}
    for(auto word:dict)
    {if(isConvertible(src,word))
    {if(visited[word]==false)
    {//Action
        path.push_back(word);
    visited[word]=true;
    solve(word,dest,dict,visited,path,ans,path_size);//Recursion
    //Backtracking
    path.pop_back();
    visited[word]=false;}
    }
    }
    return false;
}
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string>path;
        vector<vector<string>>ans;
         vector<vector<string>>finalAns;     
        int path_size=INT_MAX;
        map<string,bool>visited;
        path.push_back(beginWord);
        solve(beginWord,endWord,wordList,visited,path,ans,path_size);
        for(auto i:ans)
        {if(i.size()==path_size)
        {finalAns.push_back(i);}}
        return finalAns;

    }
};