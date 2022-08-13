#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
map<string,int>mp;
mp["ajay"]=3;
mp["karishma"]=7;
mp.insert({"kareena",45});
mp.emplace("reena",32);
mp.emplace("raveena",32);
for(auto it:mp)
{
    cout<<it.first<<" "<<it.second<<endl;
}
//or
for(auto it=mp.begin();it!=mp.end();it++)
{cout<<it->first<<" "<<it->second<<endl;}
priority_queue<int>pq;
pq.push(3);
pq.push(1);
pq.push(6);
pq.push(3);
while(!pq.empty())
{cout<<pq.top()<<" ";
pq.pop();
}
return 0;
}