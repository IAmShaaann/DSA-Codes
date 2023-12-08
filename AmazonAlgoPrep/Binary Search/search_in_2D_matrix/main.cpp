#include <iostream>
#include <vector>
using namespace std;
bool solution(vector<vector<int>> arr, int target)
{
    int rows = arr.size();
    if (rows == 0)
        return false;
    int cols = arr[0].size() - 1;
    int i = 0, j = cols;
    while (i < rows && j >= 0)
    {
        int current = arr[i][j];
        if (current == target)
            return true;
        else if (current > target)
            j--;
        else
            i++;
    }
    return false;
}

int main()
{
    return -1;
}