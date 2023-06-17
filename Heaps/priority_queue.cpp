#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq; // Max heap
    pq.push(4);
    pq.push(8);
    pq.push(2);
    pq.push(3);
    cout << "element at top : " << pq.top() << endl;
    cout << "size is : " << pq.size() << endl;
    pq.pop();
    cout << "element at top : " << pq.top();
    if (pq.empty())
    {
        cout << "pq is empty" << endl;
    }
    else
    {
        cout << "pq is not empty" << endl;
    }
    priority_queue<int, vector<int>, greater<int>> pq1; // Min heap
    pq1.push(4);
    pq1.push(8);
    pq1.push(2);
    pq1.push(3);
    cout << "element at top : " << pq1.top() << endl;
    cout << "size is : " << pq1.size() << endl;
    pq1.pop();
    cout << "element at top : " << pq1.top();
    return 0;
}