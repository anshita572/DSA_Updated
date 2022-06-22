#include <iostream>
using namespace std;
void sayDigit(int n, string arr[])
{
    if (n == 0)    //base case
    {
        return; 
    }
    int lastDigit = n % 10;   //processing
    n = n / 10;
    sayDigit(n, arr);     //recursive call
    cout << arr[lastDigit] << " ";
}  //Tail recursion
int main()
{
    int number;
    cout << "Enter a number" << endl;
    cin >> number;
    string arr[10] = {"zero", "one", "two", "three", "four",
                      "five", "six", "seven", "eight", "nine"};
    sayDigit(number, arr);
}

