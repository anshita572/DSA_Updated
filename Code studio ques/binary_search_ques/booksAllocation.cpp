//https://www.codingninjas.com/codestudio/problems/allocate-books_1090540?leftPanelTab=0
bool isPossible(vector<int> arr, int n, int m,int mid)
{
    int studentCount=1; //given in constraints that
    //there is atleast one student
    int pageSum=0;
    for(int i=0;i<n;i++)
    { if(pageSum+arr[i]<=mid)
    {pageSum=pageSum+arr[i];}
    else  //if(pageSum+arr[i]> mid)
    {
        studentCount++;
        if(studentCount>m || arr[i]>mid)
        {return false;}
        pageSum=arr[i];
    }  
     
     if(studentCount > m)
     {return false;}
    }
    return true;
     
}
int allocateBooks(vector<int> arr, int n, int m) {
    int sum=0;
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    int start=0;
    int end=sum;
   
    while(start<=end)
    {  int mid=start + (end-start)/2;
        if(isPossible(arr,n,m,mid)) //if possible solution exists
    {
        ans=mid;
        end=mid-1;
    }
    else  //if no possible solution exists
    {
        start=mid+1;
    }
    }
    return ans;
}