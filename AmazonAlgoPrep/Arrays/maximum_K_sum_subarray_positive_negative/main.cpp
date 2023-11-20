#include <iostream>
#include <vector>
using namespace std;
int bad_brute_force(vector<int> arr, int K)
{
    long long sum = 0;
    int n = arr.size();
    int max_length = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = j; k < n; k++)
            {
                sum += arr[k];
                if (sum == K)
                {
                    max_length = max(max_length, k - i + 1);
                }
            }
            sum = 0;
        }
    }
    return max_length;
}
int better(vector<int> arr, int K)
{
    long long sum = 0;
    int max_length = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == K)
            {
                max_length = max(max_length, j - i + 1);
            }
        }
        sum = 0;
    }
    return max_length;
}
int solution(vector<int> arr, int K)
{
    long long sum = 0;
    int max_length = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == K)
        {
            max_length = max(max_length, i + 1);
        }
        int remaining = K - arr[i];
        if (map.find(remaining) != map.end())
        {
            int length_so_far = i - map[remaining];
            max_length = max(max_length, length_so_far);
        }
        if (map.find(sum) == map.end())
        {
            map[sum] = 1;
        }
    }

    return max_length;
}

int main()
{
    int arr[] = {
        2, 1, 1, 1, 3, 4, 5};
    vector<int> vec;
    int K = 5;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec, K);
    return 0;
}