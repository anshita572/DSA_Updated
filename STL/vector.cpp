#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
vector<int>v;
cout<<"Size : "<<v.size()<<endl;
v.push_back(1);
cout<<"Size : "<<v.size()<<endl;
v.push_back(2);
cout<<"Size : "<<v.size()<<endl;
v.pop_back();
cout<<"Size : "<<v.size()<<endl;
v.clear();
cout<<"Size : "<<v.size()<<endl;
vector<int>v1;
v1.push_back(1);
v1.push_back(2);
v1.push_back(3);
v1.push_back(4);
for(auto i=v1.begin();i!=v1.end();i++)
{cout<<*i<<" ";}
cout<<endl;

//copying
vector<int> v2(v1);
for(auto it:v2)
{cout<<it<<" ";}
cout<<endl;
vector<int>v3(v1.begin(),v1.end());
for(auto it:v3)
{cout<<it<<" ";}
cout<<endl;
//copying first 2 elements
vector<int>v4(v1.begin(),v1.begin()+2);
for(auto it:v4)
{cout<<it<<" ";}
cout<<endl;
//2D vector
vector<vector<int>>vec;
vector<int>v5;
v5.push_back(1);
v5.push_back(2);
vec.push_back(v5);
vector<int>v6;
v6.push_back(10);
v6.push_back(20);
v6.push_back(30);
vec.push_back(v6);
cout<<vec[1][2]<<endl;
cout<<vec[0][0]<<endl;
//printing using for each loop
for(auto i:vec)
{for(auto j:i)  
{cout<<j<<" ";}
cout<<endl;}
//printing in traditional loop
for(int i=0;i<vec.size();i++)
{
    for(int j=0;j<vec[i].size();j++)
    {cout<<vec[i][j]<<" ";}
    cout<<endl;
}
//define a vector of 4X5 initially having all zeroes
vector<vector<int>>vec2(4,vector<int>(5,0));
//3D vector 5X6X7
vector<vector<vector<int>>>vec3(5,vector<vector<int>>(6,vector<int>(7)));
return 0;
}