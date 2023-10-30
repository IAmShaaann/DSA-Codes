#include <iostream>
#include <vector>
using namespace std;
void solution(vector<int> &arr)
{
    int start = 0;
    int mid = 0;
    int end = arr.size() - 1;
    while (mid <= end)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[start]);
            start++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[end]);
            end--;
        }
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
}
int main()
{
    int arr[] = {1, 2, 0};
    vector<int> vec;
    int K = 1;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    solution(vec);
    return 0;
}