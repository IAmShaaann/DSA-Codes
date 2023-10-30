#include <iostream>
#include <vector>
using namespace std;

int broken_solution(vector<int> arr)
{
    int break_point = 0;
    int break_point_value = 0;
    int next_greater = 0;
    vector<int> res;

    for (int i = 0; i < arr.size(); i++)
    {
        res.push_back(arr[i]);

        if (arr[i] < arr[i + 1])
        {
            break_point = i;
            break_point_value = arr[i];
            break;
        }
    }
    vector<int> partial_vector(arr.begin() + break_point + 1, arr.end());
    sort(partial_vector.begin(), partial_vector.end());

    for (int i = 0; i < partial_vector.size(); i++)
    {
        if (partial_vector[i] > break_point_value)
        {
            swap(res[res.size() - 1], partial_vector[i]);
            break;
        }
    }

    for (int i = 0; i < partial_vector.size(); i++)
    {
        res.push_back(partial_vector[i]);
    }
    for (auto it : res)
    {
        cout << it << " ";
    }

    return -1;
}

void solution(vector<int> arr)
{
    int index = -1;
    int n = arr.size();
    if (n == 1)
    {
        return;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }

    for (int i = n - 1; i > index; i--)
    {
        if (arr[i] > arr[index])
        {
            swap(arr[i], arr[index]);
            break;
        }
    }
    reverse(arr.begin() + index + 1, arr.end());
    for (auto it : arr)
    {
        cout << it << " ";
    }
}
int main()
{
    int arr[] = {1};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    solution(vec);
    return 0;
}