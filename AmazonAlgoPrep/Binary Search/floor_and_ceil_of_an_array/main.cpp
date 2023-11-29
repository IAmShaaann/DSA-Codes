#include <iostream>
#include <vector>
using namespace std;

int floor(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;
    int res = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] <= target)
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}
int ceil(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;
    int res = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] >= target)
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
void solution(vector<int> arr, int target)
{
    int floor_value = floor(arr, target);
    int ceil_value = ceil(arr, target);
    cout << "Floor: " << floor_value << " "
         << "Ceil: " << ceil_value << endl;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 7;
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);
    solution(vec, target);
    return -1;
}