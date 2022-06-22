#include<iostream>
using namespace std;
int mySqrt(int n) {
        int start=0;
        int end=n;
        int ans=0;
        while(start<=end)
        {
            long long int mid=start + (end-start)/2;
            if((mid*mid)==n)
            {return mid;}
            else if((mid*mid)>n)
            {end=mid-1;}
            else //if(mid*mid<n)
            {ans=mid;
            start=mid+1;}
        }
        return ans;
    }
double morePrecision(int n,int precision,int intSol)
{
    double ans=intSol;
    double factor =1;
    for(int i=0;i<precision;i++)
    {factor=factor/10;
    for(double j=ans;j*j < n;j=j+factor)
    {
        ans=j;
    }
}
return ans;
}
int main(){
int n;
cout<<"Enter a number"<<endl;
cin>>n;
int precision;
cout<<"Enter the degree of precision"<<endl;
cin>>precision;
int intSol=mySqrt(n);
cout<<"Sqrt of "<<n<<" upto "<<precision<<" decimal digits is : "
<<morePrecision(n,precision,intSol);
return 0;
}