// https://www.geeksforgeeks.org/sum-digit-number-using-recursion/
#include <iostream>
using namespace std;
int findSum(int n)
{
  if (n == 0)
  {
    return 0;
  }
  int lastDigit = n % 10;
  return (lastDigit + findSum(n / 10));
}
int main()
{
  int n;
  cout << "Enter a number : " << endl;
  cin >> n;
  // int sum=0;
  cout << "Sum of digits of " << n << " : " << findSum(n);

  return 0;
}