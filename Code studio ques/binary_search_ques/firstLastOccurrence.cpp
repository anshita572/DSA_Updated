//First/Last Occurrence of an Element in array: https://bit.ly/3Ioexjh
int firstOcc(vector<int>& arr, int n, int key)
{
    int s=0;
    int e=n-1;
    int ans=-1;// If ‘Key’ is not present in the array,
    //then the first and the last occurrence will be -1 
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]==key)
        {ans=mid;
        e=mid-1;}
        else if(key>arr[mid])
        {s=mid+1;}
        else //if(key<arr[mid])
        {e=mid-1;}
    }
    return ans;
}
int lastOcc(vector<int>& arr, int n, int key)
{
    int s=0;
    int e=n-1;
    int ans=-1;// If ‘Key’ is not present in the array,
    //then the first and the last occurrence will be -1 
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]==key)
        {ans=mid;
        s=mid+1;}
        else if(key>arr[mid])
        {s=mid+1;}
        else //if(key<arr[mid])
        {e=mid-1;}
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
   pair<int,int>p;
    p.first=firstOcc(arr,n,k);
    p.second=lastOcc(arr,n,k);
    return p;
} 