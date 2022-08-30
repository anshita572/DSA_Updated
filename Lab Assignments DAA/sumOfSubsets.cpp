#include<iostream>
using namespace std;

    class Subset_Sum
    {
        public:    
        void subsetsum_Backtracking(int Set[] , int pos, int sum,
         int tmpsum, int size, bool & found)
        {
            if (sum == tmpsum)
                found = true;
            for (int i = pos; i < size; i++)
            {
             if (tmpsum + Set[i] <= sum)
               {
                  tmpsum += Set[i];   
                 
                  subsetsum_Backtracking(Set, i + 1, sum, tmpsum, size, found);
                  tmpsum -= Set[i];
                }
            }
        }
    };
    
    int main()
    {
        int i, n, sum;
        Subset_Sum S;
        cout << "Enter the number of elements in the set" << endl;
        cin >> n;
        int a[n];
       cout<<"Enter the elements of array"<<endl;
       for(int i=0;i<n;i++)
       {
           cin>>a[n];

       }cout
    }