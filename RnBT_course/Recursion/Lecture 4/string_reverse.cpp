#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//M1
// void solve(vector<char>& s,int l,int h)
//     {
//         if(l>=h)
//         {return;}
//         swap(s[l],s[h]);
//         solve(s,l+1,h-1);
//     }
//     void reverseString(vector<char>& s) {
//         solve(s,0,s.size()-1);
//     }

//M2
void reverse(string s,int index,string &ans)
{
    if(index==s.length())
    {return;}
    reverse(s,index+1,ans);
    ans.push_back(s[index]);
}
int main(){
string s="hello";
string ans="";
reverse(s,0,ans);
for(int i=0;i<s.length();i++)
{cout<<ans[i];}
return 0;
}