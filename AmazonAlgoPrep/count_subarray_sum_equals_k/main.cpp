#include <iostream>
#include <vector>
using namespace std;
int solution(vector<int> arr, int K)
{
    int sum = 0;
    int cnt = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        int difference = sum - K;
        cnt += map[difference];
        map[sum]++;
    }
    return cnt;
}
int main()
{
    int arr[] = {1, 1, 1};
    vector<int> vec;
    int K = 2;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec, K);
    return 0;
}