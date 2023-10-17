#include <iostream>
#include <vector>
using namespace std;
int solution(vector<int> arr)
// if there is an element having count more than n/2. time_complexity = O(N) space_complexity - O(1)
{
    int element;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (cnt == 0)
        {
            element = arr[i];
            cnt++;
        }
        else if (arr[i] == element)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    return element;
}

int main()
{
    int arr[] = {6, 5, 5};
    vector<int> vec;
    int K = 1;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec);
    return 0;
}