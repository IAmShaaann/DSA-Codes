#include <iostream>
#include <vector>
using namespace std;

int brute_force(vector<int> arr) // Bad brute_force.
{
    int cnt = 0;
    int maxCnt = 0;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            for (int k = j; k < arr.size(); k++)
            {
                sum += arr[k];
                if (sum == 0)
                {
                    maxCnt = max(maxCnt, k - j + 1);
                }
            }
            sum = 0;
        }
    }
    return maxCnt;
}

int better(vector<int> arr)
{
    int cnt = 0;
    int maxCnt = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                maxCnt = max(maxCnt, j - i + 1);
            }
        }
        sum = 0;
    }
    return maxCnt;
}
int solution(vector<int> arr)
{
    int cnt = 0;
    int maxCnt = 0;
    int sum = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxCnt = max(maxCnt, i + 1);
        }
        else
        {
            if (map.find(sum) != map.end())
            {
                maxCnt = max(maxCnt, i - map[sum]);
            }
            else
            {
                map[sum] = i;
            }
        }
    }
    return maxCnt;
}

int main()
{
    int arr[] = {1, 45, 22, 0, 10, -37, 37, 29, 23, 2, 9, 0, 2, 15, 49, 6, 27, 25, 35, 50, 39, 1, 42, 49, 20, 33, 28, 40, 26, 14, 38, 26, 25, 16, 49};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec);
    return 0;
}
