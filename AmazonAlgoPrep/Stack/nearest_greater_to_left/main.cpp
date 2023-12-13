#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
    Input -> [5,2,6,7,2,5] => Output -> [-1, 5, -1, -1, 7, 7]; Return the nearest greater element from left of arr[i]
*/

vector<int> solution(vector<int> arr)
{
    vector<int> res;
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        if (st.size() == 0)
        {
            res.push_back(-1);
        }
        else if (st.size() != 0 and st.top() > arr[i])
        {
            res.push_back(st.top());
        }
        else if (st.size() != 0 and st.top() < arr[i])
        {
            while (!st.empty() && st.top() < arr[i])
            {
                st.pop();
            }

            if (st.empty())
                res.push_back(-1);
            else
            {
                if (st.top() > arr[i])
                    res.push_back(st.top());
                else
                    res.push_back(-1);
            }
        }
        st.push(arr[i]);
    }
    return res;
}
int main()
{
    int arr[] = {1, 3, 5, 2, 4, 0};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);

    vector<int> res = solution(vec);
    for (int it : res)
    {
        cout << it << " ";
    }

    return -1;
}