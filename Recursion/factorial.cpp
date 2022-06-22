#include <iostream>
using namespace std;
int factorial(int n)
{
	if (n == 0) // base case
	{
		return 1;
	}
	return n * factorial(n - 1); // recurrence relation
}

int main()
{
	int n;
	cout << "Enter a number" << endl;
	cin >> n;
	cout << "Factorial of " << n << " = " << factorial(n) << endl;
}
