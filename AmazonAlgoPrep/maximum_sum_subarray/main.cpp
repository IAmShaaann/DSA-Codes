#include <iostream>
#include <vector>
using namespace std;
int better(vector<int> arr) // time_complexy - O(N2) space_complexity = O(1)
{
    long long sum = 0;
    long long max_sum = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += arr[k];
            max_sum = max(sum, max_sum);
        }
        sum = 0;
    }
    return max_sum;
}
int solution(vector<int> arr) // time_complexity - O(N) space_complexity = O(1)
    long long sum = 0;
long long mx = INT_MIN;
for (int i = 0; i < arr.size(); i++)
{
    sum += arr[i];
    mx = max(mx, sum);
    if (sum < 0)
    {
        sum = 0;
    }
}
return mx;
}

int main()
{
    int arr[] = {5, 4, -1, 7, 8};
    vector<int> vec;
    int K = 1;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec);
    return 0;
}