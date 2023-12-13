#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> solution(vector<int> arr)
{
    vector<int> res;
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (st.empty())
            res.push_back(-1);
        else if (!st.empty() and st.top() < arr[i])
            res.push_back(st.top());
        else if (!st.empty() and st.top() > arr[i])
        {
            while (!st.empty() and st.top() > arr[i])
            {
                st.pop();
            }
            if (st.empty())
                res.push_back(-1);
            else
            {
                if (st.top() < arr[i])
                    res.push_back(st.top());
                else
                    res.push_back(-1);
            }
        }
        st.push(arr[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    int arr[] = {4, 2, 10, 6, 3, 5, 12};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);

    vector<int> res = solution(vec);
    for (auto it : res)
    {
        cout << it << " ";
    }

    return -1;
}