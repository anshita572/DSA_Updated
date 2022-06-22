//https://bit.ly/3r8UJcf
void reverse(string& s,int i,int j)//pass by reference
{   
    //base case
    if(i>j)
    {return;}
    swap(s[i],s[j]);
    //recursive call
    reverse(s,i+1,j-1);
}
string reverseString(string str)
{
	// Write your code here.
   reverse(str,0,str.length()-1);
    return str;
}