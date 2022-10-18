// https://www.codingninjas.com/codestudio/problems/subsequences-of-string_985087?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_16
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void subseq(string s, string ans, vector<string> &res, int i)
{
    if (i == s.length())
    {
        if (ans != "")
        {
            res.push_back(ans);
        }
        return;
    }
    subseq(s, ans + s[i], res, i + 1);
    subseq(s, ans, res, i + 1);
}
vector<string> subsequences(string str)
{

    vector<string> res;
    string ans = "";
    subseq(str, ans, res, 0);
    return res;
}
