#include <iostream>
#include <vector>
using namespace std;
vector<int> better(vector<int> arr)
// if there is an element having count more than n/2. time_complexity = O(N) space_complexity - O(N)
{

    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
        map[arr[i]]++;
    }
    vector<int> ans;
    int n = arr.size() / 3;
    for (auto it : map)
    {
        if (it.second >= n)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}
vector<int> solution(vector<int> arr)
{
    int c1 = 0, c2 = 0, e1 = INT_MIN, e2 = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (c1 == 0 && e2 != arr[i])
        {
            c1 = 1;
            e1 = arr[i];
        }
        else if (c2 == 0 && e1 != arr[i])
        {
            c2 = 1;
            e2 = arr[i];
        }
        else if (arr[i] == e1)
            c1++;
        else if (arr[i] == e2)
            c2++;
        else
        {
            c1--, c2--;
        }
    }
    vector<int> res;
    int mini = (arr.size() / 2);
    c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == e1)
            c1++;
        if (arr[i] == e2)
            c2++;
    }

    if (c1 >= mini)
        res.push_back(e1);
    if (c2 >= mini)
        res.push_back(e2);

    return res;
}

int main()
{
    int arr[] = {3, 2, 3};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    vector<int> result = solution(vec);
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}