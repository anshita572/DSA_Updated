#include <iostream>
#include <bits/stdc++.h>
#include<array>
using namespace std;
int main()
{
    array<int, 4> arr = {1, 2, 3, 4};
    //printing the array
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        cout <<"Element : "<< *it << " Address : ";
        cout<<it<<" ";
        cout<<endl;
    }
    cout << endl;
    //for each loop
    for(auto it:arr)
    {cout<<it<<" ";}//printing the array
     cout << endl;
    //reverse print
    for(auto it=arr.rbegin();it!=arr.rend();it++)
    { cout << *it << " ";}
    cout<<endl;
    //reverse print
    for(auto it=arr.end()-1;it>=arr.begin();it--)
    { cout << *it << " ";}
    cout<<endl;
    cout<<"Size : "<<arr.size()<<endl;
    cout<<arr.front()<<endl;
    cout<<arr.at(0)<<endl;
    cout<<arr.back()<<endl;
    cout<<arr.at(arr.size()-1)<<endl;
    return 0;
}