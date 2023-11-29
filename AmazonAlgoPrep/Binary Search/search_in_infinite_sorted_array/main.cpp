#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> arr, int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int solution(vector<int> arr, int target)
{
    int low = 0;
    int high = 1;
    while (low <= high)
    {
        if (high < target)
        {
            low = high;
            high *= 2;
        }
        else if (high >= target)
        {
            return binary_search(arr, low, high, target);
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 24};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec, 24); // Index = 1
    cout << solution(vec, 5);  // Not found  = -1
    return 0;
}