#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
string s="cba";
bool ans=next_permutation(s.begin(),s.end());
if(ans)
{cout<<s<<endl;}
else //if it is the last permutation,1st permutation will be printed
{
cout<<s<<endl;}
return 0;
}