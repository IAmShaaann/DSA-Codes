#include <iostream>
#include <vector>
using namespace std;
// Bitonic Array -  an array having a peak.
int solution(vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid - 1] < arr[mid] and arr[mid] > arr[mid + 1])
            return arr[mid];
        else if (arr[mid] > arr[mid - 1] and arr[mid] < arr[mid + 1]) // the increasing order.
            low = mid + 1;
        else if (arr[mid] < arr[mid - 1] and arr[mid] > arr[mid + 1]) // the decreasing order.
            high = mid - 1;
    }
}
int main()
{
    int arr[] = {1, 4, 8, 3, 2};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);
    cout << solution(vec);

    return -1;
}

// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3
