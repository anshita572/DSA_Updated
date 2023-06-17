// https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

// acc to ques,1-based indexing

// Heapify
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] < arr[smallest])
        {
            smallest = left;
        }
        if (right < n && arr[right] < arr[smallest])
        {
            smallest = right;
        }
        if (smallest != i)
        {
            swap(arr[smallest], arr[i]); // arr[i] apni sahi jagah pe pahunch gya
            heapify(arr, n, smallest);   // recursive call so that arr[smallest] apni sahi jagah pe pahunch jaaye
        }
    }
vector<int> buildMinHeap(vector<int> &arr)
{int n=arr.size();
    for (int i = n / 2-1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    return arr;
}
