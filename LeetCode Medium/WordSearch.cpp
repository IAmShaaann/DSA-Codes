/*
Question: 
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
*/

class Solution
{
public:
    bool exist(vector<vector<char>> &arr, string word)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[0].size(); j++)
            {
                if (arr[i][j] == word[0] and dfs(i, j, arr, 0, word))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int i, int j, vector<vector<char>> arr, int count, string word)
    {
        if (count == word.size())
        { // found the complete word
            return true;
        }
        if (i < 0 or j < 0 or i >= arr.size() or j >= arr[0].size() or arr[i][j] != word[count])
        { // check for out of bound or incorrect word.
            return false;
        }
        char temp = arr[i][j];
        arr[i][j] = ' ';
        bool found = dfs(i + 1, j, arr, count + 1, word) or
                     dfs(i - 1, j, arr, count + 1, word) or
                     dfs(i, j + 1, arr, count + 1, word) or
                     dfs(i, j - 1, arr, count + 1, word);
        arr[i][j] = temp;
        return found;
    }
};