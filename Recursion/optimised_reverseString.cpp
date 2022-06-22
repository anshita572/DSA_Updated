//using only one pointer i and reusing it for j
//i.e. j=n-i-1 where n=length of string
#include<iostream>
using namespace std;
void reverseString(string& s,int i,int n)//pass by reference
{ //  cout<<s<<endl; //(To understand what is happening)
    //base case
    if(i>n-1)     //j=n-1 where n=length of string
    {return;}
    swap(s[i],s[n-1]); 
    //recursive call
    reverseString(s,i+1,n-i-1);
}
int main(){
string str;
cout<<"Enter the string"<<endl;
getline(cin,str);
reverseString(str,0,str.length());
cout<<str<<endl;
return 0;
}