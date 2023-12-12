#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
vector<int> brute_force(vector<int> arr)
{
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] > arr[i])
            {
                res.push_back(arr[j]);
                break;
            }
            if (j == arr.size() - 1)
            {
                res.push_back(-1);
            }
        }
    }
    res.push_back(-1);
    return res;
}

vector<int> solution(vector<int> arr)
{
    vector<int> res;
    stack<int> st;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (st.size() == 0)
        {
            res.push_back(-1);
        }
        else if (st.size() > 0 and arr[i] < st.top())
        {
            res.push_back(st.top());
        }
        else if (st.size() > 0 and arr[i] > st.top())
        {
            while (arr[i] > st.top())
            {
                st.pop();
            }
            if (st.size() == 0)
                res.push_back(-1);
            else
            {
                if (st.top() > arr[i])
                {
                    res.push_back(st.top());
                }
                else
                {
                    res.push_back(-1);
                }
            }
        }
        st.push(arr[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int arr1[] = {4, 1, 2};
    int arr2[] = {1, 3, 4, 2};
    vector<int> v1, v2, res;
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
        v1.push_back(arr1[i]);

    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
        v2.push_back(arr2[i]);

    res = solution(v2);
    for (int i : res)
    {
        cout << i << " ";
    }
    return -1;
}