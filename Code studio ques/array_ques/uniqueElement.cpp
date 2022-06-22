//https://bit.ly/3y01Zdu
int findUnique(int *arr, int size)
{for(int i=0;i<size-1;i++)
{
    for(int j=i+1;j<size;j++)
    {
        if(arr[i]!=arr[j])
        {return arr[i];}
    }
}
}
//Optimised solution using XOR
//a^a=0 ,a^0=a (1^1=0,1^0=1)

int findUnique(int *arr, int size)
{
    int ans=0;
    for(int i=0;i<size;i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}
vector<int> v;
v.push_back (nums[i]);