#include <iostream>
#include <vector>
using namespace std;

vector<int> brute_force(vector<int> arr)
{
    vector<int> result;
    bool is_valid = true;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] > arr[i])
            {
                is_valid = false;
                break;
            }
        }

        if (is_valid)
        {
            result.push_back(arr[i]);
        }
        is_valid = true;
    }
    return result;
}
vector<int> solution(vector<int> arr)
{
    vector<int> res;
    int max_value = INT_MIN;
    int n = arr.size();
    res.push_back(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max_value)
        {
            res.push_back(arr[i]);
            max_value = max(arr[i], max_value);
        }
    }

    return res;
}

int main()
{
    int arr[] = {4, 7, 1, 0};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    vector<int> res = solution(vec);
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}