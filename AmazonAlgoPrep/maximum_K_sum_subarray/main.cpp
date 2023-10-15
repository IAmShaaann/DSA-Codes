#include <iostream>
#include <vector>
using namespace std;
int brute_force(vector<int> arr, int K) // time_complexity - ~ O(N3) space_complexity - O(1)
{
    int subarray_size = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            long long sum = 0;
            for (int k = i; k < j; k++)
            {
                sum += arr[k];
            }
            if (sum == K)
            {
                subarray_size = max(subarray_size, j - i);
            }
        }
    }
    return subarray_size;
}
int better_brute_force(vector<int> arr, int K) // time_complexity - ~ O(N2) space_complexity - O(1)
{
    int subarray_size = 0;
    int n = arr.size();
    long long sum = arr[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == K)
            {
                subarray_size = max(subarray_size, j - i + 1);
            }
        }
        sum = 0;
    }
    return subarray_size;
}
int better(vector<int> arr, int K) // time_complexity - ~ O(N * 1(finding the element in the map))  space_complexity - O(N) - storing the sums in the map.
{
    int max_length = 0;
    unordered_map<long long, int> map;
    long long sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == K)
        {
            max_length = max(max_length, i + 1);
        }
        long long remaining = sum - K;
        if (map.find(remaining) != map.end())
        {
            int len = i - map[remaining];
            max_length = max(max_length, len);
        }
        if (map.find(sum) == map.end()) // if the sum is already in the map. dont add a duplicate value.
        {
            map[sum] = i;
        }
    }
    cout << "max: " << max_length << endl;
}
int solution(vector<int> arr, int K)
{
    int max_length = 0;
    long long sum = arr[0];
    int left = 0;
    int right = 0;
    while (right < arr.size()) // time_complexity - ~ O(N )  space_complexity - O(1)
    {
        {
            while (left <= right && sum > K) // This loop will almost run for O(N) time in its entire cycle.
            {
                sum -= arr[left];
                left++;
            }
            if (sum == K)
            {
                max_length = max(max_length, right - left + 1);
            }
            right++;
            if (right < arr.size())
            {
                sum += arr[right];
            }
        }
        cout << "max: " << max_length << endl;

        return max_length;
    }
}
int main()
{
    int arr[] = {2, 0, 0, 0, 0, 3};
    vector<int> vec;
    int K = 3;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    solution(vec, K);
    return 0;
}