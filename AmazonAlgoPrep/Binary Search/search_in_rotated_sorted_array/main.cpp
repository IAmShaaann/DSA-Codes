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

        if (arr[low] <= arr[mid])
        {                                                  // left half is sorted.
            if (target >= arr[low] and target <= arr[mid]) // target is in the left half.
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (target >= arr[mid] and target <= arr[high]) // target is in the right half.
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {11, 12, 15, 18, 19, 20, 2, 5, 6, 8, 9};
    int target = 8;
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);
    cout << solution(vec, target);
    return 0;
}