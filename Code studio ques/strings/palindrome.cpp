//Check Palindrome:https://bit.ly/3E55FvF 
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
bool checkPalindrome(string s)
{
    int i=0;
    int j=s.size()-1;
    while(i<=j)
    {
       if(isalnum(s[i])==0)//if s[i] is not alphanumeric
       {i++;}
        else if(isalnum(s[j])==0)//if s[j] is not alphanumeric
        {j--;}
        else if(toLowercase(s[i])!=toLowercase (s[j]))
        { return false;
            
        }
        
        else  //if(ch[i]==ch[j])
        {i++;
         j--;}
    }
   return true;
}