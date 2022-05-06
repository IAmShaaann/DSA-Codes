#include <bits/stdc++.h>
using namespace std;
// At each index we'll calculate current max.
int maxSubArrayKadane(vector<int> arr)
{
    int maxSoFar = 0;
    int mx = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        mx = mx + arr[i];             // calcuate the current max.
        mx = max(mx, 0);              // prevent sum from going negative.
        maxSoFar = max(mx, maxSoFar); // check for max from available values.
    }
    return maxSoFar;
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArrayKadane(arr);
}