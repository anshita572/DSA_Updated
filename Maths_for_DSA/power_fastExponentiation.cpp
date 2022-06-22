//Time Compexity : O(log(b))
#include<iostream>
using namespace std;
int pow(int a,int b)   //a^b (a to the power b)
{
    int result=1;
    for(int i=0;i<b/2;i++)
    {
        result=result*a;
    }
    if(b % 2==0)  //if b is even
    {return result*result;}
    else //if b is odd
    {return result*result*a;}

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