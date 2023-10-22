#include <iostream>
#include <vector>
using namespace std;
void brute_force(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                for (int k = 0; k < n; k++)
                {
                    if (arr[k][j] != 0)
                    {
                        arr[k][j] = -1;
                    }
                }
                for (int l = 0; l < m; l++)
                {
                    if (arr[i][l] != 0)
                    {
                        arr[i][l] = -1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void better(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<int> rows(n, 0);
    vector<int> columns(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                rows[i] = -1;
                columns[j] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rows[i] == -1 || columns[j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 0, 0, 0}, {1, 1, 1, 0}, {1, 0, 1, 0}};
    solution(arr);
    return 0;
}