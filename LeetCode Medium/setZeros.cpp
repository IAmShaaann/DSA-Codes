/*Question: Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 */
#include <bits/stdc++.h>
class Solution
{
public:
    void setZeroes(vector<vector<int>> &arr)
    {
        int rows = arr.size();
        int cols = arr[0].size();
        vector<int> ro(rows, -1), co(cols, -1);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (arr[i][j] == 0)
                {
                    ro[i] = 0;
                    co[j] = 0;
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (ro[i] == 0 || co[j] == 0)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }
};