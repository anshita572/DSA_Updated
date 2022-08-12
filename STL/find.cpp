#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
//Find the index of first occurrence of an element in a vector
vector<int>v={1,2,5,1,4,5,2,4};
//Find first occurrence of 2
auto it=find(v.begin(),v.end(),2);
if(it==v.end())
{
    cout<<"Element not present"<<endl;
}
else
{cout<<"Index = "<<it-v.begin();}
