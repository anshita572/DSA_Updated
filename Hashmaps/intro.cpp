#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
//creation
unordered_map<string,int>m;
//insertion
//M1
pair<string,int>p1=make_pair("a",1);
m.insert(p1);
//M2
pair<string,int>p2("b",2);
m.insert(p2);
//M3
m["c"]=3;
//Search
//M1
cout<<m["a"]<<endl;
// //M2
cout<<m.at("b")<<endl;
//Size
cout<<m.size()<<endl;
//Imp
// cout<<m.at("d")<<endl;//error =>value corresponding to "d" does not exist
// cout<<m["d"]<<endl;//0 =>entry of 0 will be created corresponding to "d"
// cout<<m.at("d")<<endl;// 0 now after line 25
// to check if present
cout<<m.count("e")<<endl; //absent =>0
cout<<m.count("c")<<endl;//present =>1
//erase
m.erase("a");
cout<<m.size()<<endl;
//Accesing all elements
//M1
for(auto i:m)
{
    cout<<i.first<<" "<<i.second<<endl;
}
//M2 using iterator
unordered_map<string,int> :: iterator it=m.begin();
while(it != m.end())
{
    cout<<it->first<<" "<<it->second<<endl;
    it++;
}

return 0;
}