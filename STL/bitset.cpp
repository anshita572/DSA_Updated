#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
bitset<4>bt;
cout<<"Enter 4 bits"<<endl; 
cin>>bt;
cout<<bt<<endl;
bool ans1=bt.all();
if(ans1)
{cout<<"True"<<endl;}
else
{cout<<"False"<<endl;}
bool ans2=bt.any();
if(ans2)
{cout<<"True"<<endl;}
else
{cout<<"False"<<endl;}
cout<<bt.count()<<endl;
bt.flip();
cout<<"After flipping all bits : "<<bt<<endl;
bt.flip(2);
cout<<bt<<endl;
bool ans3=bt.none();
if(ans3)
{cout<<"True"<<endl;}
else
{cout<<"False"<<endl;}
bool ans4=bt.test(1);
if(ans4)
{cout<<"True"<<endl;}
else
{cout<<"False"<<endl;}
int arr[5]={3,22,4,1,5};
int mini=*max_element(arr,arr+5);
cout<<mini<<endl;
return 0;
}