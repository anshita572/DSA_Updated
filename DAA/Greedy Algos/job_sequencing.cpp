#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct job{
	char id;
	int dead;
	int profit;
};
bool cmp(job a,job b)
{
	return (a.profit>b.profit);
}
void js(job arr[],int n)
{
	sort(arr,arr+n,cmp);
	int result[n];
	bool slot[n];
	
	for (int i=0;i<n;i++)
	{
		slot[i]=false;
	}
	for (int i=0;i<n;i++)
	{
		for (int j=min(n,arr[i].dead-1);j>=0;j--)
	{
		 if(slot[j]==false)
		 {
		 	result[j]=i;
		 	slot[j]=true;
		 	break;
		 	
		 }
	}
	
	}
	for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
	
}

	int main()
{
    job arr[] = { { 'a', 2, 20 },
                  { 'b', 2, 15 },
                  { 'c', 1, 10 },
                  { 'd', 3, 5 },
                  { 'e', 3, 1 } };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs "
            "\n";
 
    // Function call
    js(arr, n);
    return 0;
}
