//Range of int : -2^31 to 2^31
//INT_MAX=2^31 and INT_MIN= -2^31
#include<iostream>
using namespace std;
int main(){
int arr[5]={-3,-2,-5,-1,-4};
int n=5;
int maxi=INT_MIN;
int mini=INT_MAX;
for(int i=0;i<n;i++)
{
    if(arr[i]>maxi)
    {maxi=arr[i];}
    //OR
    //maxi=max(maxi,arr[i]);
}
for(int i=0;i<n;i++)
{
    if(arr[i]<mini)
    {mini=arr[i];}
    //OR
     //mini=max(mini,arr[i]);
}
cout<<"Max element :"<<maxi<<endl;
cout<<"Min element :"<<mini<<endl;
return 0;
}