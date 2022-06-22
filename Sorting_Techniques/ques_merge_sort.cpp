// https://bit.ly/3JNFk9u

void merge(vector < int > & arr,int start,int end)
{   int mid=start+(end-start)/2;
    int n1=mid-start+1;  //n1 : length of first subarray
    int n2=end-mid;     //n2 : length of second subarray
    int *subArray1=new int[n1]; 
    int *subArray2=new int[n2];
//copying values from arr to subArray1
int k=start;
for(int i=0;i<n1;i++)
{
    subArray1[i]=arr[k++];
}
//copying values from arr to subArray2
 k=mid+1;
for(int j=0;j<n2;j++)
{
    subArray2[j]=arr[k++];
}
//merging and sorting the 2 subarrays
int i=0;     //i : index for subArray1
int j=0;    //j : index for subArray2
k=start;    //k : index for arr i.e. which is our main array
while(i<n1 && j<n2)
{if(subArray1[i]<subArray2[j])
{
    arr[k++]=subArray1[i++];
}
else       //if(subArray2[j]<subArray1[i])
{
    arr[k++]=subArray2[j++];
}
}
if(i>n1)//subArray1 is finished but some elements of 
//subArray2 are still remaining,so copy those elements of
//subArray2 in arr
{
    while(j<n2)
    {
      arr[k++]=subArray2[j++];
    }
}
else      //(j>n2)
//subArray2 is finished but some elements of 
//subArray1 are still remaining,so copy those elements of
//subArray1 in arr
{
    while(i<n1)
    {
      arr[k++]=subArray1[i++];
    }
}
delete []subArray1;
delete []subArray2;
}

void mergeSortSolve(vector < int > & arr,int start,int end)
{//base case
    if(start>=end)
    {return;}
int mid=start+(end-start)/2;
    
    //else (start,end)
    mergeSortSolve(arr,start,mid);//recursive call
    mergeSortSolve(arr,mid+1,end);//recursive call
    merge(arr,start,end);//calling merge function
}

void mergeSort(vector < int > & arr, int n) {
    mergeSortSolve(arr,0,n-1);
}