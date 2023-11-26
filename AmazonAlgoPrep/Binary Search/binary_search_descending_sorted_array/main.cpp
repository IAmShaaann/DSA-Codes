#include <iostream>
#include <vector>
using namespace std;
int solution(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec, 2); // Index = 1
    cout << solution(vec, 9); // Not found  = -1
    return 0;
}