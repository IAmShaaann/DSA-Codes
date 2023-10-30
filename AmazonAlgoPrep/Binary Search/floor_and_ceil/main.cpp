#include <iostream>
#include <vector>
using namespace std;
// lowerbound of an array is an element that is greater than all the smaller elements in the array.
int solution(vector<int> nums, int target)
{
}

int main()
{

    int arr[] = {1, 2, 4, 7};
    vector<int> values;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        values.push_back(arr[i]);
    }
    int target = 6;
    cout << solution(values, target);
    return 0;
}