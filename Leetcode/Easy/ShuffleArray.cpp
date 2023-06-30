/*
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].


*/

#include <bits/stdc++.h>
class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        //         3, 4, 5, 6, 7, 8 -> 3, 6, 4, 7, 5, 8
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int next = i + n y;
            arr.push_back(nums[i]);
            arr.push_back(nums[next]);
        }
        return arr;
    }
};