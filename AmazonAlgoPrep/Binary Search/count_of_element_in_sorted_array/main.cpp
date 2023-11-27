#include <iostream>
#include <vector>
using namespace std;
int first_occurance(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int answer = -1;
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            answer = mid;
            high = mid - 1;
        }
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return answer;
}

int last_occurance(vector<int> arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;
    int answer = -1;
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            answer = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return answer;
}
int solution(vector<int> arr, int target)
{
    int first = first_occurance(arr, target);
    int last = last_occurance(arr, target);
    return last - first + 1;
}
int main()
{
    int arr[] = {5, 5, 10, 10, 10, 10, 20};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);

    int target = 10;
    cout << solution(vec, target);

    return -1;
}