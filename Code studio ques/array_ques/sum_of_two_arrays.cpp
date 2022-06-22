//https://bit.ly/3DXfsDZ 
vector<int>reverse(vector<int>arr)
{  int i=0;
 int j=arr.size()-1;
    while(i<=j)
{ swap(arr[i],arr[j]);
    i++;
    j--;
}
    return arr;
}
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	vector<int>ans;
    int i=n-1;
    int j=m-1;
    int carry=0;
    while(i>=0 && j>=0)
    {
        int sum=a[i]+b[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while(i>=0) //when i wala array is large and it is remaining
      {
        int sum=a[i]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        i--;
    }   
     while(j>=0) //when j wala array is large and it is remaining
      {
        int sum=b[j]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
         j--;
    }  
    while(carry!=0) //both arrays are finished but carry is remaining
    {
        int sum=carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
    }
    return reverse(ans);
}