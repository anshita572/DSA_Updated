//https://practice.geeksforgeeks.org/problems/convert-a-sentence-into-its-equivalent-mobile-numeric-keypad-sequence0547/1
//TC :O(n)   SC:O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
string printSequence(string S)
{ string ans="";
    vector<string>v(26);
    v={"2","22","222","3","33","333","4","44","444","5","55","555",
        "6","66","666","7","77","777","7777","8","88","888","9",
        "99","999","9999"};
    for(int i=0;i<S.length();i++)
    { if(S[i]==' ')
    {ans+="0";}
        ans+=v[S[i]-'A'];
    }
    return ans;
}