#include <iostream>
#include <vector>
using namespace std;
int iterative(vector<int> arr, int K)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == K)
        {
            return mid;
        }
        else if (arr[mid] > K)
        {
            end = mid;
        }
        else
        {
            start = mid;
        }
    }
    return -1;
}

int recursive(vector<int> arr, int K, int start, int end)
{
    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == K)
        return mid;
    else if (arr[mid] > K)
    {
        return recursive(arr, K, 0, mid - 1);
    }
    else
        return recursive(arr, K, mid + 1, arr.size() - 1);
}
int solution(vector<int> arr, int K)
{
    return recursive(arr, K, 0, arr.size() - 1);
}
int main()
{

    int arr[] = {-1, 0, 3, 5, 9, 12};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    int target = 9;
    cout << solution(values, target);
    return 0;
}