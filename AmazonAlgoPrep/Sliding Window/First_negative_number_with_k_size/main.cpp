#include <iostream>
#include <vector>
using namespace std;
/*
    Question - Given an array A[] of size N and a positive integer K, find the
    first negative integer for each and every window(contiguous subarray) of size K.
    Example - arr = [-8, 2, 3, -6, 10] | K = 2
    Output - -8 0 -6 -6
*/

int brute_force(vector<int> arr, int K)
{
    int size = arr.size() - K + 1;
    vector<int> res;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < i + K; j++)
        {
            if (arr[j] < 0)
            {
                cout << arr[j] << " ";
                break;
            }
            if (j == K + i - 1)
            {
                cout << 0 << " ";
            }
        }
    }
    return 0;
}

int solution(vector<int> arr, int K)
{

    queue<long long> q;
    vector<long long> ans;
    for (int i = 0; i < K - 1; i++)
    {
        if (arr[i] < 0)
        {
            q.push(arr[i]);
        }
    }

    for (int i = K - 1; i < arr.size(); i++)
    {
        if (arr[i] < 0)
            q.push(arr[i]);
        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(q.front());
            if (q.front() == arr[i - K + 1])
                q.pop();
        }
    }
    return ans;
}

int main()
{

    int arr[] = {-8, 2, 3, -6, 10};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    int K = 2;
    cout << solution(values, K);
    return 0;
}