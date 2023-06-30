/* Question: There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 */

#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> arr, int k)
{
    int n = arr.size();
    int i = 0, j = 0;
    int sum = 0;
    int mini = INT_MAX;
    int arrsum = 0;
    for (auto x : arr)
        arrsum += x;
    if (k == n)
        return arrsum; // if k==n then we can take all cards
    while (j < n)
    {
        sum += arr[j];
        if (j - i + 1 < n - k)
        {
            j++;
        }
        else
        {
            mini = min(mini, sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return arrsum - mini;
}
int main()
{
    vector<int> arr = {11, 49, 100, 20, 86, 29, 72};
    cout << solution(arr, 4);
}