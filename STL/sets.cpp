#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
//ordered set
set<int>s;
s.insert(8);
s.insert(3);
s.insert(2);
s.insert(3);
for(auto i:s)
{cout<<i<<" ";}
cout<<endl;
cout<<s.count(3)<<endl;
auto it=s.find(2);
cout<<*it<<endl;
cout<<endl;
//unordered set
unordered_set<int>s1;
s1.insert(8);
s1.insert(3);
s1.insert(2);
for(auto i:s1)
{cout<<i<<" ";}
cout<<endl;
multiset<int>ms;
ms.insert(3);
ms.insert(5);
ms.insert(2);
ms.insert(3);
ms.insert(5);
ms.insert(6);
for(auto i:ms)
{cout<<i<<" ";}
cout<<endl;
ms.erase(3);//all instances of 3 will be erased
ms.clear();//entire multiset will be erased
return 0;
}