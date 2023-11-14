#include <iostream>
#include <vector>
using namespace std;
/*
    Question - Given an array and window size K, Find the max sum subarray with given K.
    Example - array = [2, 5, 1, 8, 2, 9, 1] | K = 4 | Output = 20 - [8, 2 ,9 ,1]
*/

int brute_force(vector<int> arr)
{
    int mx = INT_MIN;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < i + 3; j++)
        {
            sum += arr[j];
            mx = max(mx, sum);
        }
        sum = 0;
    }
    return mx;
}
int solution(vector<int> arr, int window)
{
    int mx = INT_MIN;
    int sum = 0;
    for (int i = 0; i < window; i++)
    {
        sum += arr[i];
    }
    for (int i = window; i < arr.size(); i++)
    {
        sum -= arr[i - window];
        sum += arr[i];
        mx = max(sum, mx);
    }

    return mx;
}

int main()
{

    int arr[] = {2, 5, 1, 8, 2, 9, 1};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    int K = 4;
    cout << solution(values, K);
    return 0;
}