/*
There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.
Ex: Input: gain = [-5,1,5,0,-7]
Output: 1
Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.

 */
#include <bits/stdc++.h>
class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        vector<int> ans;
        ans.push_back(0);
        int mx = 0;
        for (int i = 0; i < gain.size(); i++)
        {
            int diff = ans[i] + gain[i];
            if (diff > mx)
            {
                mx = diff;
            }
            ans.push_back(diff);
        }
        return mx;
    }
};