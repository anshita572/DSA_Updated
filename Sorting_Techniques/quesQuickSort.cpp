//https://bit.ly/3qZ6LEC
int partition(vector<int>& arr,int start,int end)
{
    int pivot=arr[start]; //pivot is element at 0th index
    // i.e pivot is at 0th index (pivotIndex=0)
    int count=0;
    for(int i=start+1;i<=end;i++)
    {if(arr[i]<=pivot)
      {  count++;}
      }
    int pivotIndex=start+count;
    //swapping the pivot element i.e. at index 0 with 
   //element at pivotIndex
    swap(arr[pivotIndex],arr[start]);
//Now after swapping the pivot element,it is at it's right position
int i=start;
int j=end;
while(i<pivotIndex && j>pivotIndex)
{while(arr[i]<=pivot)   //pivot=arr[pivotIndex]
{
    i++;
}
while(arr[j]>pivot)
{
    j--;
}
if(i<pivotIndex && j>pivotIndex)
{swap(arr[i++],arr[j--]);
}
}

return pivotIndex;
}
void solveQuickSort(vector<int>& arr,int start,int end)
{
    //base condition
    if(start>=end)
    {return;}
    int p=partition(arr,start,end);
    //Sorting the left part
    solveQuickSort(arr,start,p-1); //recursive call
    //Sorting the left part
    solveQuickSort(arr,p+1,end);  //recursive call
}
vector<int> quickSort(vector<int> arr)
{
    solveQuickSort(arr,0,arr.size()-1);
    return arr;
}
