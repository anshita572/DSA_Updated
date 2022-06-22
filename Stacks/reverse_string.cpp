//Reverse a string using stack
//TC : O(N)
//SC : O(N)   (extra space of stack is used)
#include<iostream>
#include<stack>
using namespace std;
int main(){
stack<char>s;
string str="abcd";
for(int i=0;i<str.length();i++)  
{
    s.push(str[i]);  //push the entire string into stack
}
string ans="";
while(!s.empty())   //jab tak stack empty nhi hota
{
    char ch=s.top();    //top element ko ans m daalo and then pop it
    ans.push_back(ch);
    s.pop();
}
cout<<ans<<endl;
return 0;
}