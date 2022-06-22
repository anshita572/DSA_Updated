//Time Compexity : O(b)
#include<iostream>
using namespace std;
int pow(int a,int b)   //a^b (a to the power b)
{
    int result=1;
    for(int i=0;i<b;i++)
    {
        result=result*a;
    }
return result;
}
int main(){
int a,b;
cout<<"Enter base number"<<endl;
cin>>a;
cout<<"Enter power number"<<endl;
cin>>b;
cout<<pow(a,b);
return 0;
}