#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void add(string s1,string s2,int i,int j,int carry,vector<int>&ans)
{if(i<0 && j<0 && carry==0)
{return;}
int first=0;
int second=0;
//convert string to int by subtracting ASCII value
if(i>=0)
{first=s1[i]-'0';}
if(j>=0)
{second=s2[j]-'0';}
int sum=first+second+carry;
int last_dig=sum%10;
carry=sum/10;

add(s1,s2,i-1,j-1,carry,ans);
ans.push_back(last_dig);

}
int main(){
string s1="61";
string s2="79";
vector<int>ans;
add(s1,s2,s1.length()-1,s2.length()-1,0,ans);
// reverse(ans.begin(),ans.end());
for(auto i:ans)
{cout<<i;}
return 0;
}