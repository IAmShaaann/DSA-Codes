// Question : Given an unsorted integer array, find a pair with the given sum in it.

#include <bits/stdc++.h>
using namespace std;
void checkSumBrute(vector<int> arr, int target)
{
    //	brute force solution, find all occurances and then choose the correct option.
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            int diff = arr[i] + arr[j];
            if (diff == target)
            {
                cout << arr[i] << " " << arr[j];
            }
        }
    }
}
void checkSumBinary(vector<int> arr, int target)
{
    //	Sort the array and apply binary search.
    int low = 0;
    int high = arr.size() - 1;
    sort(arr.begin(), arr.end());
    while (low < high)
    {
        if (arr[low] + arr[high] == target)
        {
            cout << arr[low] << " " << arr[high];
            return;
        }
        else if (arr[low] + arr[high] > target)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
}

void checkSumHash(vector<int> arr, int target)
{
    // using hashmap
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
        if (map.find(target - arr[i]) != map.end())
        {
            cout << arr[map[target - arr[i]]] << " " << arr[i] << endl;
        }
        map[arr[i]] = i;
    }
}

int main()
{
    vector<int> arr = {8, 7, 2, 5, 3, 1};
    int target = 10;
    checkSumHash(arr, target);
}