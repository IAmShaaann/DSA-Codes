#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> brute_force(vector<vector<int>> arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end})
    }
}

vector<vector<int>> solution(vector < vector<int> arr)
{
    vector << vector < int >> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || ans.back()[1] < arr[i][0])
        {
            ans.push_back(arr[i]);
        }
        else
        { // ans is not empty and the last item's last element is greated than arr[i][0]- merge it.
            ans.back()[1] = max(arr[i][1], ans.back()[1]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 9}, {14, 16}};
    vector<vector<int>> result = solution(arr);
    return 0;
}