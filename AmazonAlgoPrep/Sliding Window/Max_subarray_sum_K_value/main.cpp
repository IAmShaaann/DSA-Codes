#include <iostream>
#include <vector>
using namespace std;

int brute_force(vector<int> arr)
{
    int mx = INT_MIN;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < i + 3; j++)
        {
            sum += arr[j];
            mx = max(mx, sum);
        }
        sum = 0;
    }
    return mx;
}
int solution(vector<int> arr)
{
    int mx = INT_MIN;
    int sum = arr[0] + arr[1] + arr[2];

    for (int i = 3; i < arr.size(); i++)
    {
        sum -= arr[i - 3];
        sum += arr[i];
        mx = max(mx, sum);
    }
    return mx;
}

int main()
{

    int arr[] = {1, 2, 3, 3, 5, 2, 3};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    cout << solution(values);
    return 0;
}