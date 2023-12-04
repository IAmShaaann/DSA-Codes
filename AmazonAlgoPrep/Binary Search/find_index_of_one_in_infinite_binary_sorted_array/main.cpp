#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> arr, int low, int high, int target)
{
    int mid = 0;
    int res = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            res = mid;
            high = mid - 1;
        }
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return res;
}
int solution(vector<int> arr)
{
    int low = 0;
    int high = 1;
    int target = 1;
    while (low <= high)
    {
        if (arr[low] < target and arr[high] >= target)
        {
            return binary_search(arr, low, high, 1);
        }
        else
        {
            low = high;
            high *= 2;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);

    cout << solution(vec);
    return -1;
}