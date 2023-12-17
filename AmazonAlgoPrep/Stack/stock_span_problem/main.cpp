#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> solution(vector<int> arr)
{
    vector<int> res;
    stack<int> st;

    for (int i = 0; i < arr.size(); i++)
    {
        if (st.empty())
        {
            res.push_back(1);
        }
        else if (!st.empty() and st.top() > arr[i])
        {
            res.push_back(1);
        }
        else if (!st.empty() and st.top() < arr[i])
        {
            int stackSize = st.size();
            while (!st.empty() && st.top() < arr[i])
            {
                stackSize--;
                st.pop();
            }
            res.push_back(i - stackSize + 1);
        }
        st.push(arr[i]);
    }
    return res;
}
int main()
{
    int arr[] = {3, 4, 2, 7, 5, 8, 10, 6};

    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);

    vector<int> res = solution(vec);
    for (auto it : res)
        cout << it << " ";
    return -1;
}