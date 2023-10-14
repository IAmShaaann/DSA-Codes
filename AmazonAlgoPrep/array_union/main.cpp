#include <iostream>
#include <vector>
using namespace std;
void solution(vector<int> arr1, vector<int> arr2)
{
    vector<int> arr3;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            if (arr3.size() == 0 || arr3.back() != arr1[i])
            {
                arr3.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (arr3.size() == 0 || arr3.back() != arr2[j])
            {

                arr3.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < arr1.size())
    {
        if (arr3.size() == 0 || arr3.back() != arr1[i])
        {
            arr3.push_back(arr1[i]);
        }
        i++;
    }
    while (j < arr2.size())
    {
        if (arr3.size() == 0 || arr3.back() != arr2[j])
        {

            arr3.push_back(arr2[j]);
        }
        j++;
    }

    for (auto it : arr3)
    {
        cout << it << " ";
    }
}
int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    int n = 10;
    int m = 7;
    vector<int> vec1;
    vector<int> vec2;

    for (int i = 0; i < n; i++)
    {
        vec1.push_back(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        vec2.push_back(arr2[i]);
    }
    solution(vec1, vec2);
}