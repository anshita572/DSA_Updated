//Sort 0 1 2 [https://bit.ly/3DfQW0s]
//Approach : Using 3 pointers  OR Dutch National Flag Algorithm Approach
//Time Complexity : O(n)
void sort012(int *arr, int n)
{
   int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {swap(arr[low],arr[mid]);
        arr[low++];
         arr[mid++];
        }
          else if(arr[mid]==1)
        {
         arr[mid++];
        }
          else //if(arr[mid]==2)
        {swap(arr[mid],arr[high]);
        arr[high--];
        }
    }
}