//Binary Search: https://bit.ly/3eQrSna
int solveBinarySearch(int arr[],int start,int end,int key)
{
   
    if(start>end)
    {return -1;}
    int mid=start+(end-start)/2;
    if(arr[mid]==key)
    {return mid;}
    else if(arr[mid]>key) 
    {return solveBinarySearch(arr,start,mid-1,key);}//recursive call
    else    //if(arr[mid]<key)
    {return solveBinarySearch(arr,mid+1,end,key);}//recursive call
}
int binarySearch(int *input, int n, int val)
{
    int ans=solveBinarySearch(input,0,n-1,val);
}