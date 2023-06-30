/*Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).

A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].

If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.

Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.*/

// Note: The solution for this problem is same as PivotIndex problem.

#include <bits/stdc++.h>class Solution {
public:
int findMiddleIndex(vector<int> &nums)
{
    int total = 0;
    for (auto it : nums)
    {
        total += it;
    }
    int current = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (current == (total - current - nums[i]))
        {
            return i;
        }
        current += nums[i];
    }
    return -1;
}
}
;