#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> nums, int target, bool findStartIndex)
{
    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            if (findStartIndex)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return ans;
}

int solution(vector<int> arr, int target)
{
    if (nums.size() == 0)
    {
        return {-1, -1};
    }
    int first = search(nums, target, true);
    int last = search(nums, target, false);
    return {first, last};
}

int main()
{

    int arr[] = {3, 4, 13, 13, 13, 20, 40};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    int target = 13;
    cout << solution(values, target);
    return 0;
}