//TC : O(n*W) where W is capacity of knapsack and n=no.of items in knapsack
#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int val[],int W,int n)

{
	int i,w;
	int k[n+1][W+1];
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0||w==0)
			{
				k[i][w]=0;
			}
			else if(wt[i-1]<=w)
			{
				k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
			}
			else
			{
				k[i][w]=k[i-1][w];
			}
			
		}
	}
	return k[n][W];
}
int main()
{
	int val[] = {2,3,4,1 };
    int wt[] = {3,4,5,6};
    int W = 8;
    int n = 4;
      
    cout << knapsack(wt,val,W,n);
      
    return 0;
}
