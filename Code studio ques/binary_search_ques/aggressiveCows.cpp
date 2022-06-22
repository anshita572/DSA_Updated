//Aggressive Cows: https://bit.ly/3dkuQ2B 
bool isPossible(vector<int> &stalls, int k,int mid,int n)
{
    int cowCount=1;
    int lastPos=stalls[0];//on number line we always start from 0
    //in our sorted array
        for(int i=0;i<n;i++)
        {
            if(stalls[i]-lastPos >=mid)
            {cowCount++;
            if(cowCount==k)
            {return true;}
            lastPos=stalls[i];
        }
        }
        return false;
    
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int ans=-1;
    int start=0;
    int end=stalls[n-1];
    
    while(start<=end)
    {int mid= start+(end-start)/2;
        if(isPossible(stalls,k,mid,n))
        {ans=mid;
        start=mid+1;}
        else
        {end=mid-1;}
    }
    return ans;
}