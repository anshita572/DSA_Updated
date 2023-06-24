// https://leetcode.com/problems/find-median-from-data-stream/description/
// TC : O(n log n) , SC : O(n)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
public:
    MedianFinder()
    {
    }
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void addNum(int x)
    {
        if (maxHeap.empty() || maxHeap.top() > x)
        {
            maxHeap.push(x);
        }
        else
        {
            minHeap.push(x);
        }
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (minHeap.size() == maxHeap.size()) // even
        {
            double median = (maxHeap.top() + minHeap.top()) / 2.0;
            return median;
        }
        else if (minHeap.size() > maxHeap.size()) // odd
        {
            return minHeap.top();
        }
        else
        {
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */