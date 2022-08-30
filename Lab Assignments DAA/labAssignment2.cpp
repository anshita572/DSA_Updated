//job sequence
#include<iostream>
#include<algorithm>
using namespace std;
struct job{
int deadline;
char id;
int profit;
};
bool comparison(job A,job B)
{
return(A.profit>B.profit);
}
void printScheduling(job arr[],int n)
{
    sort(arr,arr+n,comparison);
    int result[n];
    bool slot[n];
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i].deadline)-1;j>=0;j--)
        {
            if(slot[j]==false)
            {
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }
   for (int i=0; i<n; i++)
	if (slot[i])
     cout << arr[result[i]].id << " ";

    
}


int main(){

return 0;
}