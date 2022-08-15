//This code is for case sensitive i.e upper and lower
//case alphabets are considered to be different
//characters (e.g. : Abba is not a palindrome)
#include<iostream>
using namespace std;
bool checkPalindrome(char ch[],int n)
{
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        if(ch[i]!=ch[j])
        { return false;
            
        }
        else  //if(ch[i]==ch[j])
        {i++;
         j--;}
    }
   return true;
}
int getLength(char ch[])
{
    int count=0;
for(int i=0;ch[i]!='\0';i++)
{count++;}
return count;

}
int main(){
char name[30];
cout<<"Enter a string"<<endl;
cin>>name;
int n=getLength(name);
if(checkPalindrome(name,n))
{cout<<"Yes,this is a palindrome"<<endl;}
else
{cout<<"No,this is not a palindrome"<<endl;}
return 0;
}