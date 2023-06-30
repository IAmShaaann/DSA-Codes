/* Given an m x n matrix, return all elements of the matrix in spiral order.
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/

/*for this solution we take one row or column at a time.and each row will be considered as level. initially you are at the top most level
left to right: as soon as you hit right, you are at the right most level, you change your direction to top to bottom now you traverse and add all the elements of top to bottom, you hit bottom you change the direction, right to left and now you are at the bottom most level. you traverse from right to left and as soon as you hit the left wall you change the level


*/
#include<bits/stdc++.h>
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &arr)
    {
        int m = arr.size();
        int n = arr[0].size();
        int direction = 1;
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        vector<int> ans;

        while (left <= right and top <= bottom)
        {
            if (direction == 1)
            {
                for (int i = left; i <= right; i++)
                    ans.push_back(arr[top][i]);
                direction = 2;
                top++;
            }
            else if (direction == 2)
            {
                for (int i = top; i <= bottom; i++)
                    ans.push_back(arr[i][right]);
                direction = 3;
                right--;
            }
            else if (direction == 3)
            {
                for (int i = right; i >= left; i--)
                    ans.push_back(arr[bottom][i]);
                direction = 4;
                bottom--;
            }
            else if (direction == 4)
            {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(arr[i][left]);
                direction = 1;
                left++;
            }
        }
        return ans;
    }
};