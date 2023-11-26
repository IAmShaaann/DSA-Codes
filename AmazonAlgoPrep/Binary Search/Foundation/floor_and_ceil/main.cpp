#include <iostream>
#include <vector>
using namespace std;
// lowerbound of an array is an element that is greater than all the smaller elements in the array.

int get_upper_bound(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int get_lower_bound(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
void solution(vector<int> nums, int target)
{
    int floor = get_lower_bound(nums, target);
    int ceil = get_upper_bound(nums, target);
    cout << "floor: " << floor << " " << ceil;
}

int main()
{

    int arr[] = {3, 4, 4, 7, 8, 10};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    int target = 8;
    solution(values, target);
    return 0;
}