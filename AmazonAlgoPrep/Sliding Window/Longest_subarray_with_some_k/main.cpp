#include <iostream>
#include <vector>
using namespace std;
int better(vector<int> arr, int K)
{
    int max_length = 0;
    int sum = 0;
    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            if (sum == K)
                max_length = max(max_length, j - i + 1);
        }
        sum = 0;
    }
    return max_length;
}
int solution(vector<int> arr, int targetSum)
{
    int start = 0, end = 0;
    int maxValue = 0;
    int tempSum = 0;
    while (end < arr.size())
    {

        tempSum += arr[end];

        if (tempSum < targetSum)
        {
            end++;
        }
        else if (tempSum == targetSum)
        {
            maxValue = max(maxValue, (end - start + 1));
            end++;
        }
        else if (tempSum > targetSum)
        {
            while (tempSum > targetSum)
            {
                tempSum -= arr[start];
                start++;
            }
            end++;
        }
    }

    return maxValue;
}

int main()
{
    int arr[] = {
        2,
        14,
        6,
        8,
        2,
        3,
        7,
        1,
    };
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    int K = 20;
    cout << solution(values, K);
    return 0;
}