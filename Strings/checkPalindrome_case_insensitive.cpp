//Case insensitive (captital ho ya small alphabets,farak nhi pdta)
//We will convert all characters into lowercase
//and then will check for palindrome
#include<iostream>
using namespace std;
char toLowercase(char ch)
{
if(ch>='a' && ch<='z') //i.e. ch is lowercase
{return ch;}
else //if(ch>='A' && ch<='Z')//i.e. ch is uppercase
{
    char temp = ch- 'A'+'a'; //coverting uppercase to lowercase
    return temp;
}
}
bool checkPalindrome(char ch[],int n)
{
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        if(toLowercase(ch[i])!=toLowercase (ch[j]))
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