#include <iostream>
#include <vector>
using namespace std;
void brute_force(vector<int> a, vector<int> b)
{
    vector<int> c;
    int m = a.size();
    int n = b.size();
    for (auto it : a)
    {
        c.push_back(it);
    }
    for (auto it : b)
    {
        c.push_back(it);
    }
    sort(c.begin(), c.end());

    for (int i = 0; i < m; i++)
    {
        a[i] = c[i];
    }
    for (int j = 0; j < (m + n); j++)
    {
        b[j] = c[j + m];
    }
    for (auto it : a)
    {
        cout << it << " ";
    }
    for (auto it : b)
    {
        cout << it << " ";
    }
}
void solution(vector<int> a, vector<int> b)
{
    vector<int> c;
    int m = a.size();
    int n = b.size();
    int left = 0;
    int right = 0;
    int index = 0;
    while (left < m && right < n)
    {
        if (a[left] < b[right])
        {
            c[index] = a[left];
            left++;
            index++;
        }
        else if (a[left] > b[right])
        {
            c[index] = b[right];
            right++;
            index++;
        }
    }

    for (auto it : c)
    {
        cout << it << " ";
    }
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    vector<int> vec1;
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
    {
        vec1.push_back(arr1[i]);
    }
    int arr2[] = {0, 2, 6, 8, 9};

    vector<int> vec2;
    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
    {
        vec2.push_back(arr2[i]);
    }
    solution(vec1, vec2);

    return -1;
}