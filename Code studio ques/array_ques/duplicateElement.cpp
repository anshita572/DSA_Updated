//Duplicates in Array [https://bit.ly/3dm6bdZ]
//‘ARR’ of size ‘N’ containing each number between 1 
//and N-1 at least once.Imp line in ques
int findDuplicate(vector<int> &arr) 
{int n=arr.size();
 int ans=0;
  for(int i=0;i<n;i++)
  {//XOR ing all elements
      ans=ans^arr[i];
  }
 for(int i=1;i<n;i++)
 {//XOR [1,n-1]
     ans=ans^i;
 }
	return ans;
}
