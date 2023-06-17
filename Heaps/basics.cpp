// zero-based indexing
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;
    heap() // Constructor
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val) // Insertion in max heap
    {
        size = size + 1;
        int index = size; // index=1
        arr[index] = val; // arr[1]=val
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deleteFromHeap() // deletion of root node
    {
        if (size == 0)
        {
            cout << "Nothing to delete as heap is empty" << endl;
            return;
        }
        // put last node element as root node
        arr[1] = arr[size];
        // delete last node
        size--;
        int i = 1;
        while (size > 1)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (leftIndex < size && arr[i] < arr[leftIndex] && arr[leftIndex] > arr[rightIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }

            else if (rightIndex < size && arr[i] < arr[rightIndex] && arr[rightIndex] > arr[leftIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    h.print();
     
    return 0;
}