//https://www.geeksforgeeks.org/first-uppercase-letter-in-a-string-iterative-and-recursive/
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
char upper(string s,int i,char ans)
{
    // if(s[i]=='\0')
    // {return 0;} OR
    if(i==s.length())
    {return ans;}
    if(s[i]>='A' && s[i]<='Z')
    {ans=s[i];
    return ans;}
  return upper(s,i+1,ans);
}
int main(){
    int n;
string s="bYe";
char ans='0';
ans=upper(s,0,ans);
cout<<ans;
return 0;
}