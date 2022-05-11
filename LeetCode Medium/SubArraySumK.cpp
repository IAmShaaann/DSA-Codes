#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> nums, int k)
{
    int N = nums.size();
    unordered_map<int, int> hmap;
    if (N == 1)
    {
        if (nums[0] == k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int ans = 0, sum = 0;
    hmap[sum] = 1;
    for (int i = 0; i < N; i++)
    {
        sum += nums[i];

        if (hmap.find(sum - k) != hmap.end())
        {
            ans += hmap[sum - k];
        }
        hmap[sum]++;
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    cout << solution(arr, 3);
}