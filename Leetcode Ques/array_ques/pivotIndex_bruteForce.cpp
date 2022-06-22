 //https://leetcode.com/problems/find-pivot-index/
 //Time Compelxity :O(n^2)
 #include<iostream>
using namespace std;
 int pivotIndex(int nums[],int n) {
       // int n=nums.size();
       // int pivot=0;
        int leftSum=0;
        int rightSum=0;
        for(int pivot=0;pivot<n;pivot++)
        {//int pivot is actually my pivot index
            for(int i=0;i<pivot;i++)
            {leftSum=leftSum+nums[i];}
           // cout<<"left sum = "<<leftSum<<endl;
            for(int j=pivot+1;j<n;j++)
            {rightSum=rightSum+nums[j];}
           // cout<<"right sum = "<<rightSum<<endl;
            if(leftSum==rightSum)
            {return pivot;}
           else  //if(leftSum != rightSum)
           {
               leftSum=0;
               rightSum=0;
           }
          //  {pivot++;}   
        }
        return -1;
    }
    int main(){
int n;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of array"<<endl;
	for(int i=0;i<n;i++)
	{ cin>>arr[i];
	}
    cout<<pivotIndex(arr,n);
    }