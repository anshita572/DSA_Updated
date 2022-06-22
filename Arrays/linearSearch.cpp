#include<iostream>
using namespace std;
bool linearSearch(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        return 1;
    }
    return 0;
}
int main(){
int arr[6]={3,1,-5,9,15,-8};
int n=6;
int key;
cout<<"Enter the key"<<endl;
cin>>key;
 if(linearSearch(arr,n,key))
 {cout<<"Key is present"<<endl;}
 else
 {cout<<"Key is not present"<<endl;}
return 0;
}