// Given an integer array, find the maximum product of two integers in it.
// For example, consider array {-10, -3, 5, 6, -2}. The maximum product is the (-10, -3) or (5, 6) pair.

#include <bits/stdc++.h>
using namespace std;
int maxProdBrute(vector<int> arr)
{
    int mx = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] * arr[j] > mx)
            {
                mx = arr[i] * arr[j];
            }
        }
    }
    return mx;
}

int maxProdOptimised(vector<int> arr)
{
    int min1 = 0, min2 = 0;
    int max1 = 0, max2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min1)
        {
            min2 = min1;
            min1 = arr[i];
        }
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
    }
    return min1 * min2 > max1 * max2 ? min1 * min2 : max1 * max2;
}
// one more solution can be sort the array, find the prod of max and second max and min and second min compare both of them, which ever is higher return.

int main()
{
    vector<int> arr = {-10, -3, 5, 6, -2};
    cout << maxProdOptimised(arr);
}