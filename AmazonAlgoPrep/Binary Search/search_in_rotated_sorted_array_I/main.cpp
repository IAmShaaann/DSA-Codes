#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        // if left half is sorted.
        if (arr[low] <= arr[mid])
        {
            if (target >= arr[low] && target <= arr[mid]) // target is in the left half.
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (target >= arr[mid] && target <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{

    int arr[] = {4, 5, 6, 7, 8, 0, 1, 2, 3};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    int target = 9;
    cout << solution(values, target);
    return 0;
}