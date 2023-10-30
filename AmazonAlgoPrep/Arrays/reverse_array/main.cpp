#include <iostream>
#include <vector>
using namespace std;
// brute force - start from the end of the list, create a new list with arr[last_element--];
// optimal - have a pointer at start and end of the list, swap elements and come close.
vector<int> solution(vector<int> nums)
{
    int start = 0;
    int end = nums.size() - 1;
    while (start < end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
    return nums;
}

int main()
{
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);

    vector<int> res = solution(arr);
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}