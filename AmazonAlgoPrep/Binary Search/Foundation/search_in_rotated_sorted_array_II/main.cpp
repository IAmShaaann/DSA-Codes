#include <iostream>
#include <vector>
using namespace std;

bool solution(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return true;
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= target && target <= arr[mid])
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

            if (arr[mid] <= target && target <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{

    int arr[] = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    int target = 10;
    cout << solution(values, target);
    return 0;
}