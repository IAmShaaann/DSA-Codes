#include <iostream>
#include <vector>
using namespace std;
char solution(vector<char> arr, char target)
{
    int low = 0;
    int high = arr.size() - 1;
    char res;
    int mid = 0;
    if (arr[arr.size() - 1] == target)
    {
        return arr[0];
    }
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            res = arr[mid + 1];
            high = mid - 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
int main()
{
    char arr[] = {'a', 'c', 'h', 'j', 'm', 'p', 's', 'w', 'y'};
    vector<char> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        vec.push_back(arr[i]);
    char target = 'y';

    cout << solution(vec, target);

    return -1;
}