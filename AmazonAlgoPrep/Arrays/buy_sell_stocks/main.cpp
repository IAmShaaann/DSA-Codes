#include <iostream>
#include <vector>
using namespace std;
int brute_force(vector<int> arr)
{
    long long max_profit = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] > arr[i])
            {
                long long difference = arr[j] - arr[i];
                max_profit = max(difference, max_profit);
            }
        }
    }
    return max_profit;
}
int solution(vector<int> arr)
{
    long long max_profit = 0;
    long long min_price = INT_MAX;
    long long difference = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min_price)
        {
            min_price = arr[i];
        }
        difference = arr[i] - min_price;
        max_profit = max(max_profit, difference);
    }
    return max_profit;
}

int main()
{
    int arr[] = {7, 1, 5, 3, 6, 4};
    vector<int> vec;
    int K = 1;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec);
    return 0;
}