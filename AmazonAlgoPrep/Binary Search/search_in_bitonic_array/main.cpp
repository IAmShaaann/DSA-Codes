#include <iostream>
#include <vector>
using namespace std;
// Bitonic Array -  an array having a peak.

int binary_search(vector<int> arr, int low, int high, int target, bool isArraySorted)
{
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
        {
            if (isArraySorted)
                low = mid + 1;
            else
                high = mid - 1;
        }
        else
        {
            if (isArraySorted)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return -1;
}
int solution(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid - 1] and arr[mid] < arr[mid + 1])
        {

            int left_index = binary_search(arr, 0, mid, target, true);
            int right_index = binary_search(arr, mid, arr.size() - 1, target, false);

            return left_index == -1 ? right_index : left_index;
        }
        else if (arr[mid - 1] < arr[mid] and arr[mid] < arr[mid + 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
}
int main()
{
    int arr[] = {1, 4, 6, 7, 8, 9, 3, 2};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);
    int target = 1;
    cout << solution(vec, target);

    return -1;
}

// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3
