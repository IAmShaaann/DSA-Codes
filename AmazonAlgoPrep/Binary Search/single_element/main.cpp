#include <iostream>
#include <vector>
using namespace std;

// Solution 1 - Find occurances of all the values.
int brute_force(vector<int> arr)
{
    unordered_map<int, int> map;
    for (int i = 0l; i < arr.size(); i++)
    {
        map[arr[i]]++;
    }
    for (auto it : map)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return -1;
}
int better(vector<int> arr)
{
    // arr[i-1] != arr[i] && arr[ i +1 ] != arr[i] return arr[i];
    int start = 1;
    int end = arr.size() - 2;
    if (arr.size() == 1)
    {
        return arr[0];
    }
    if (arr[0] != arr[start])
    {
        return arr[0];
    }
    if (arr[arr.size() - 1] != arr[end])
    {
        return arr[arr.size() - 1];
    }

    for (int i = start; i <= end; i++)
    {
        if (arr[i - 1] != arr[i] && arr[i + 1] != arr[i])
        {
            return arr[i];
        }
    }
    return -1;
}

int solution(vector<int> arr)
{
    if (arr.size() == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[arr.size() - 1] != arr[arr.size() - 2])
        return arr[arr.size() - 1];

    int low = 2, high = arr.size() - 2;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }
        if (mid % 2 == 0 && arr[mid] == arr[mid + 1] || mid % 2 == 1 && arr[mid] == arr[mid - 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{

    int arr[] = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    cout << solution(values);
    return 0;
}