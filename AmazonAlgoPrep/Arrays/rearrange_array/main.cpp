#include <iostream>
#include <vector>
using namespace std;

void solution(vector<int> arr)
{
    int pos = 0;
    int neg = 1;
    vector<int> res(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            res[pos] = arr[i];
            pos += 2;
        }
        else
        {
            res[neg] = arr[i];
            neg += 2;
        }
    }
    for (auto it : res)
    {
        cout << it << "  ";
    }
    return -1;
}

int main()
{
    int arr[] = {3, 1, -2, -5, 2, -4};
    vector<int> vec;
    int K = 1;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec);
    return 0;
}