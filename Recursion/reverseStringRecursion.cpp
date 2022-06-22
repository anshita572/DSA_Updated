#include<iostream>
using namespace std;
void reverseString(string& s,int start,int end) //Imp : pass by reference
{    //base case
    if(start>end)
    {
        return;
    }
    swap(s[start],s[end]); //processing
    start++;
    end--;
    reverseString(s,start,end); //recursive call
    //OR  reverseString(s,i+1,j-1);
}
int main(){
string str;
cout<<"Enter the string"<<endl;
getline(cin,str);
reverseString(str,0,str.length()-1);
cout<<str<<endl;
return 0;
}







