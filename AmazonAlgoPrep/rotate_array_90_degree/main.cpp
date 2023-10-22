#include <iostream>
#include <vector>
using namespace std;
void solution(vector<vector<int>> &arr)
{
    vector<vector<int>> res;
    int n = arr.size();
    int m = arr[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }
}
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    solution(arr);
    return 0;
}