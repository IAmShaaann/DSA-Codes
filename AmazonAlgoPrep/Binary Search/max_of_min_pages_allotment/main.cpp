#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> arr, int students, int max)
{
    int sum = 0;
    int cnt = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum > max)
        {
            cnt++;
            sum = arr[i];
        }
        if (students < cnt)
            return false;
    }
    return true;
}

int solution(vector<int> arr, int st)
{
    int low = INT_MIN;
    int high = 0;
    int res = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        low = max(arr[i], low);
        high += arr[i];
    }
    if (arr.size() < st)
        return res;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        cout << mid << endl;
        if (isValid(arr, st, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int arr[] = {15, 10, 19, 10, 5, 18, 7};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);
    int students = 5;
    cout << solution(vec, students);
    return -1;
}