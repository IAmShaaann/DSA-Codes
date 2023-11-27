#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> arr)
{
    int size = arr.size();
    int low = 0;
    int high = size - 1;
    int mid = 0;
    int previous = 0;
    int next = 0;

    while (low <= high)
    {
        if (arr[low] <= arr[high])
        {
            return low; // Array is not rotated
        }
        mid = low + (high - low) / 2;
        next = (mid + 1) % size;            // if arr.size == 7 and mid == 7 so, high = mid + 1 == 8 => OutOfBound. So for that, mid + 1 % size will give us 8 % 7 == 1. the first index instead of out of bound element.
        previous = (mid + size - 1) % size; // if low = 0 so previous = low - 1 = -1 => OutOfBound. So for that mid - size - 1 => 0 - 7 -1 = -8 % 8 will be 0. which means array is not rotated.

        if (arr[mid] < arr[previous] and arr[mid] < arr[next])
            return mid;
        else if (arr[low] <= arr[mid])
            low = mid + 1;
        else if (arr[mid] <= arr[high])
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);

    cout << solution(vec);

    return -1;
}