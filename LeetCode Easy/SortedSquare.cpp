// The Solution to this problem is simple, start from the last ele, and keep find the larger square, and keep pushing it. 
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr)
{
    int n = arr.size();
    vector<int> v(n);
    int lo = 0;
    int hi = n - 1;
    while (n--)
    {
        if (abs(arr[lo]) > abs(arr[hi]))
        {
            v[n] = arr[lo] * arr[lo];
            lo++;
        }
        else
        {
            v[n] = arr[hi] * arr[hi];
            hi--;
        }
    }
    return v;
}
int main()
{
    vector<int> arr = {-4, -1, 0, 3, 10};
    vector<int> ans = solution(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}