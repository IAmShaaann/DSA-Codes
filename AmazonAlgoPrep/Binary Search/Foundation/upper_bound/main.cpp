#include <iostream>
#include <vector>
using namespace std;
// upperbound of an array is an element that is smaller than all the greater elements in the array.
int solution(vector<int> arr, int x)
{
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int ans = n;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        // maybe an answer
        if (arr[mid] > x)
        {
            ans = mid;
            // look for smaller index on the left
            end = mid - 1;
        }
        else
        {
            start = mid + 1; // look on the right
        }
    }
    return ans;
}

int main()
{

    int arr[] = {9, 9, 12, 12, 14, 19, 19, 28, 36, 38, 41, 45};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    int target = 28;
    cout << solution(values, target);
    return 0;
}