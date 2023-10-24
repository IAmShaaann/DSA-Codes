#include <iostream>
#include <vector>
using namespace std;
vector<int> brute_force(vector<int> arr, int target) // time_complexity - O(N2) space_complecity = O(N)
{
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
vector<int> solution(vector<int> arr, int target) // time_complexity = O(N) - Travseral and O(N) - for finding in map. = O(2N); space_complexity = O(N)
{
    vector<int> res;
    res.push_back(-1);
    res.push_back(-1);

    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
        int difference = target - arr[i];
        if (map.find(difference) != map.end())
        {
            res[0] = map[difference];
            res[1] = i;
            return res;
        }
        map[arr[i]] = i;
    }
    return res;
}
int main()
{
    int arr[] = {2, 6, 5, 8, 11};
    vector<int> vec;
    int K = 14;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    vector<int> result = solution(vec, K);
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}