#include <iostream>
#include <vector>
using namespace std;
/*
Question - When the order of sorting is not given in the question, How will you apply binary search in that case?
*/
int solution(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;
    bool isAsc = arr[0] < arr[arr.size() - 1] ? true : false;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
        {
            if (isAsc)
                low = mid + 1;
            else
                high = mid - 1;
        }
        else
        {
            if (isAsc)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {6, 5, 4, 3, 2, 1};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec, 4); // Index = 1
    cout << solution(vec, 5); // Not found  = -1
    return 0;
}