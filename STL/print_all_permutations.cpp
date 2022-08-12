#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
string s="bac";
sort(s.begin(),s.end());
do
{
    cout<<s<<endl;
} while (next_permutation(s.begin(),s.end()));

return 0;
}