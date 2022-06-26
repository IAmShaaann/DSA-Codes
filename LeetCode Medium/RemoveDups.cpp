/*
Question: Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

solution: just count the freq of each number and return the duplicate, this quesiton is basically find the duplicate.
*/

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> arr)
{
    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
        map[arr[i]]++;
    }
    for (auto it : map)
    {
        if (it.second > 1)
        {
            return it.first;
        }
    }
}
int main()
{
    vector<int> arr = {3, 1, 5, 5, 4, 2};
    cout << solution(arr);
    return 0;
}