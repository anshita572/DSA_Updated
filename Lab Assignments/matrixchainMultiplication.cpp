//Matrix chain multiplication 
#include<iostream>
using namespace std;

//parenthesization
void printParenthesis(int i, int j, int n, int* bracket,
					char& name)
{
	
	if (i == j) {
		cout << name++;
		return;
	}

	cout << "(";
	printParenthesis(i, *((bracket + i * n) + j), n,
					bracket, name);
cout << ")";
}
//minimum no of scalar multiplications
void matrixChain(int p[], int n)
{
	int m[n][n];
	int bracket[n][n];
	for (int i = 1; i < n; i++)
		m[i][i] = 0;

	
	for (int L = 2; L < n; L++)
	{
		for (int i = 1; i < n - L + 1; i++)
		{
			int j = i + L - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++)
			{
				
				int q = m[i][k] + m[k + 1][j]
						+ p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;
					bracket[i][j] = k;
				}
			}
		}
	}

	char name = 'A';

	cout << "Parenthesization is : ";
	printParenthesis(1, n - 1, n, (int*)bracket, name);
	cout << " And Optimal Cost is : " << m[1][n - 1];
}
	
int main()
{
int n;
cout<<"Enter the number of elements"<<endl;
cin>>n;
int arr[n];
cout<<"Enter the elements"<<endl;
for(int i=0;i<n;i++)
{
	cin>>arr[i];
}
matrixChain(arr,n);
return 0;

}