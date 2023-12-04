#include <iostream>
#include <vector>
using namespace std;
int first_occurance(vector<int> arr, int t)
{
    int low = 0;
    int high = arr.size() - 1;
    int res = 0;
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] <= t) // There might be an element which is greater the mid but smaller than t.
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}
int last_occurance(vector<int> arr, int t)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;
    int res = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] >= t) // There might be an element greater than t but smaller than mid.
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int solution(vector<int> arr, int target)
{
    int floor = first_occurance(arr, target);
    int ceil = last_occurance(arr, target);

    return abs(arr[floor] - target) < abs(arr[ceil] - target) ? abs(arr[floor] - target) : abs(arr[ceil] - target);
}
int main()
{
    int arr[] = {2, 4, 6, 8, 10, 16, 24};
    int target = 21;
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);
    cout << solution(vec, target);
    return -1;
}