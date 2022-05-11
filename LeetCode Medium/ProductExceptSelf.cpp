#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> arr)
{
    vector<int> ans(arr.size());
    int runningProd = 1;
    ans[0] = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        ans[i] = runningProd;
        runningProd *= arr[i];
    }
    runningProd = 1;
    vector<int> ans2(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        ans[i] *= runningProd;
        runningProd *= arr[i];
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    vector<int> ans = solution(arr);

    return 0;
}