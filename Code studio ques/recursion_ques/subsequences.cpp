// https://bit.ly/33hi3MB
#include<iostream>
#include<vector>
using namespace std;

void solve(string str,string output,int index,
 vector<string> &ans)
{  //base case;
    if(index>=str.length())
    {if(output.length()>0) //acc to ques :there no should be no empty subsequence
    {   ans.push_back(output);}
        return;
    }
    //exclude
    solve(str,output,index+1,ans);
    //include
    char element=str[index];
    output.push_back(element);
    solve(str,output,index+1,ans);
}

vector<string> subsequences(string str){
	
    vector<string>ans;
    string output="";
    int index=0;
    solve(str,output,index,ans);
    return ans;
	
}
