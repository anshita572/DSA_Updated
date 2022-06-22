//Tail recursion
//Print counting
#include<iostream>
using namespace std;
void count(int n)      
{if(n==0)            //base case
{return ;
}
else                         
{cout<<n<<endl;    //processing
count(n-1);        //recursive relation
}
}
int main()
{int n;
cout<<"Enter a number"<<endl;
cin>>n;
cout<<endl;
count(n);
}
