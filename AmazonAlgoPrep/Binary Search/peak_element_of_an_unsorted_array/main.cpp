#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> arr)
{

    int n = arr.size();
    if (n == 1)
        return 0;
    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    int low = 1;
    int high = n - 2;
    int mid = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1])
            return mid;

        if (arr[mid - 1] < arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{

    int arr[] = {30, 25, 20};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);

    cout << solution(vec);
    return -1;
}