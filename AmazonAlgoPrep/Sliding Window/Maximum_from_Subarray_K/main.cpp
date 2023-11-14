#include <iostream>
#include <vector>
using namespace std;
vector<int> brute_force(vector<int> arr, int window)
{
    vector<int> ans;
    for (int i = 0; i <= arr.size() - window; i++)
    {
        int mx = INT_MIN;
        for (int j = i; j < i + window; j++)
        {
            mx = max(mx, arr[j]);
        }
        ans.push_back(mx);
        mx = INT_MIN;
    }
    return ans;
}

vector<int> solution(vector<int> arr, int window)
{
    vector<int> ans;
    int low = 0;
    int high = 0;
    int mx = INT_MIN;

    while (low + window <= arr.size())
    {

        if (high - low + 1 == window)
        {
            mx = max(arr[high], mx);
            ans.push_back(mx);
            low++;
            high++;
        }
        else
        {
            mx = max(mx, arr[high]);
            high++;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    int K = 3;
    vector<int> res = solution(values, K);
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}