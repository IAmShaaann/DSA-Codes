
/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.*/
#include <bits/stdc++.h>
using namespace std;
// for this solution we traverse both the array s simulteneously and keep pushing smaller value in the arr. if at some point one array is empty but other has some values left, we check for them individually.

void solution(vector<int> &v1, int m, vector<int> &v2, int n)
{
    int i = 0;
    int j = 0;
    vector<int> arr;
    while (i < m and j < n)
    {
        if (v1[i] < v2[j])
        {
            arr.push_back(v1[i++]);
        }
        else
        {
            arr.push_back(v2[j++]);
        }
    }
    while (i < m)
    {
        arr.push_back(v1[i++]);
    }
    while (j < n)
    {
        arr.push_back(v2[j++]);
    }
    while (i < m + n)
    {
        v1[i] = arr[i];
    }

    for (auto it : arr)
    {
        cout << it << " ";
    }
}
int main()
{
    vector<int> v1 = {1, 2, 3, 0, 0, 0};
    vector<int> v2 = {2, 5, 6};
    int m = v1.size();
    int n = v2.size();
    solution(v1, 3, v2, n);
    return 0;
}