#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] <= arr[mid])
        {
            if (ans > arr[low])
            {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if (ans > arr[mid])
            {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }

    return index;
}

int main()
{

    int arr[] = {4, 5, 6, 7, 8, 0, 1, 2, 3};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    cout << solution(values);
    return 0;
}