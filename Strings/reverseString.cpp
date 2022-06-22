#include<iostream>
#include<string>
#include  <bits/stdc++.h>
using namespace std;
void reverse(string &ch)//Find length n from length function
{int n=ch.length();
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        swap (ch[i++],ch[j--]);
        cout<<ch<<endl;
       
    }
       
}
 int getLength(char ch[])
{
    int count=0;
for(int i=0;ch[i]!='\0';i++)
{count++;}
return count;

}
int main(){
string name;

cout<<"Enter a string"<<endl;
//cin>>name;
getline(cin,name);
//int n=getLength(name);
reverse(name);
cout<<"Reveresed string : "<<name<<endl;

return 0;
}