//https://leetcode.com/problems/permutation-in-string/
class Solution {
public:
    bool checkEqual(int arr1[26],int arr2[26])
    {   for(int i=0;i<26;i++)
    {if(arr1[i]!=arr2[i])
        {return 0;}}   //false
        return 1;      //true
    }
    bool checkInclusion(string s1, string s2) {
        int arr1[26]={0}; //storing character count of s1
        for(int i=0;i<s1.length();i++)
        {
            int count1=0;
            count1=s1[i]-'a';
            arr1[count1]++;
        }
        int windowSize=s1.length();
        int arr2[26]={0}; //storing character count of s2
        int j=0;
        //Running first window
        while(j<windowSize && j<s2.length())
        {
            int count2=0;
            count2=s2[j]-'a';
            arr2[count2]++;
            j++;
        }
        //checking if arr1 and arr2 are equal
        if (checkEqual(arr1,arr2))
        {return 1;}
        //Processing for next windows
        else
        {
        while(j<s2.length())
        {    int count2=0;
            char newChar=s2[j];
            count2=newChar-'a';
            arr2[count2]++;     //making character count 1 for next     //character(in e.g 'd')
         char oldChar=s2[j-windowSize];
         count2=oldChar-'a';
         arr2[count2]--; //making character count 0 for first    //character(in e.g 'e')
         j++;
         if (checkEqual(arr1,arr2))  //again checking if equal ,nhi toh fir se loop chlega
        {return 1;}
         
        }
        }
        return 0;   //sari windows check ho gyi ,permutation not found ,so returning false
    }
};