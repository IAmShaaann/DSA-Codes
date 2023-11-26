#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{

    int arr[] = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    cout << solution(values);
    return 0;
}