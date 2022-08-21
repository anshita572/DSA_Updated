#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void print(int n)
{int x=n;
if(n>=(-x))
{return;}
cout<<n<<" ";
print(n-1);

}
int main(){
int n;
n=5;
print(n);
return 0;
}