#include <bits/stdc++.h>
using namespace std;
void solution(vector<vector<int>> arr)
{
    stack<pair<int, int>> s;
    sort(arr.begin(), arr.end());
    pair<int, int> p;
    p.first = arr[0][0];
    p.second = arr[0][1];
    for (int i = 0; i < arr.size(); i++)
    {
        // cout << "hello";
        // pair<int, int> top = s.top();
        pair<int, int> temp;
        temp.first = arr[i][0];
        temp.second = arr[i][1];

        if (temp.second > temp.first)
        {
            int mx = max(temp.second, arr[i][1]);
            temp.second = mx;
        }
        else
        {
            s.push(temp);
            cout << temp.first << " " << temp.second;
        }
    }

    cout << s.size();
    for (int i = 0; i < s.size(); i++)
    {
        pair<int, int> top = s.top();
        cout << top.first << " " << top.second;
        s.pop();
    }
}
int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    solution(arr);
}