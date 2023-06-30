class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        vector<int> ans;
        int d = 1;
        int val = 1;
        vector<vector<int>> v(n, vector<int>(n, 0));
        while (left <= right and top <= bottom)
        {
            if (d == 1)
            {
                for (int i = left; i <= right; i++)
                {
                    ans.push_back(val++);
                }
                top++;
                d = 2;
            }
            else if (d == 2)
            {
                for (int i = top; i <= bottom; i++)
                {
                    ans.push_back(val++);
                }
                right--;
                d = 3;
            }
            else if (d == 3)
            {
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(val++);
                }
                bottom--;
                d = 4;
            }
            else if (d == 4)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(val++);
                }
                left++;
                d = 1;
            }
        }
        for (auto it : ans)
        {
            cout << it << " ";
        }
        return v;
    }
};