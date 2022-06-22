//https://leetcode.com/problems/string-compression/
class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int n=chars.size();
        
        int ansIndex=0;
        while(i<n)
        {
            int j=i+1;
            while(j<n && chars[i]==chars[j])
            {
                j++;
            }
 //we will come out of this inner while loop in 2 cases :
//either we have traversed the entire array or we have encountered a different character
            
        chars[ansIndex++]= chars[i];//storing the old character
       int count=j-i;
        if(count>1)
        {
            string s=to_string(count); //converting integer count to string 
            for(char ch : s)
            {
                chars[ansIndex++]=ch;//storing count character by character
            }
        }
        i=j;  //updtaing i
        }
        return ansIndex;
    }
};