//Sort 0 1 2 [https://bit.ly/3DfQW0s]
//Approach : count the number of 0's and 1's
//Time Complexity : O(n)
void sort012(int *arr, int n)
{
   int count0=0;
    int count1=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {count0++;}
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {count1++;}
    }
    for(int i=0;i<count0;i++)
    {arr[i]=0;}
     for(int i=count0;i<count1+count0;i++)
    {arr[i]=1;}
    for(int i=count1+count0;i<n;i++)
    {arr[i]=2;}
}