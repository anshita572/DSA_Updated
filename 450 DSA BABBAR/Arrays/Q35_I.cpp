// https://practice.geeksforgeeks.org/problems/find-the-median0527/1
// TC :O(nlogn)
// SC:O(1)

// M1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int find_median(vector<int> v)
	{
		int n = v.size();
		float start = 0;
		float end = n - 1;
		int ans = 0;
		int high = 0;
		int low = 0;
		float value = start + (end - start) / 2;
		sort(v.begin(), v.end());
		if (n % 2 != 0)
		{
			ans = v[value];
		}
		else
		{
			low = floor(value);
			high = ceil(value);
			ans = (v[low] + v[high]) / 2;
		}
		return ans;
	}
};
// M2
int find_median(vector<int> v)
{
	sort(v.begin(), v.end());
	int n = v.size();
	if (n % 2 != 0)
	{
		return v[(n) / 2];
	}
	return (v[n / 2] + v[(n / 2) - 1]) / 2;
}
