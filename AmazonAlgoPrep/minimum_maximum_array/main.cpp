#include <iostream>
#include <vector>
#include <climits> // Include this for INT_MAX and INT_MIN
using namespace std;

// brute-force = push all the values inside a minheap and maxheap, remove k element and return the top.
// better = sort the array, return arr[k] and arr[arr.size()-k];

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[left];
    int l = left + 1;
    int r = right;
    while (l <= r)
    {
        if (arr[l] < pivot && arr[r] > pivot)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
        if (arr[l] >= pivot)
        {
            l++;
        }
        if (arr[r] <= pivot)
        {
            r--;
        }
    }
    swap(arr[left], arr[r]);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return r;
}

int solution(vector<int> &arr, int k)
{
    int left = 0, right = arr.size() - 1, kth;
    while (1)
    {
        int idx = partition(arr, left, right);
        if (idx == k - 1)
        {
            kth = arr[idx];
            break;
        }
        if (idx < k - 1)
        {
            left = idx + 1;
        }
        else
        {
            right = idx - 1;
        }
    }
    return kth;
}

int main()
{
    int arr[] = {32, 12, 43, 55, 24};
    int K = 5;
    std::vector<int> array(arr, arr + sizeof(arr) / sizeof(arr[0])); // Use this constructor to initialize the vector
    cout << solution(array, K);
    return 0;
}
