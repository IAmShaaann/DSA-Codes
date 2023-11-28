#include <iostream>
#include <vector>
using namespace std;
int solution(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        int next = (mid + 1) % arr.size();
        int previous = (mid + arr.size() - 1) % arr.size();
        if (arr[mid] == target or arr[previous] == target or arr[next] == target)
        {
            if (arr[mid] == target)
                return mid;
            else if (arr[previous] == target)
                return previous;
            else
                return next;
        }
        else if (arr[previous] < target)

            low = mid + 2;

        else
            high = mid - 2;
    }
    return -1;
}
int main()
{
    int arr[] = {5, 10, 30, 20, 40};
    int target = 20;
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);
    cout << solution(vec, target);
    return -1;
}