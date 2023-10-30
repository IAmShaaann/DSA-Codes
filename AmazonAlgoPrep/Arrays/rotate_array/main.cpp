#include <iostream>
#include <vector>
using namespace std;
void solution(vector<int> arr, int K)
{
    int temp;

    K %= arr.size();

    for (int i = 0; i < K; i++)
    {
        temp = arr[arr.size() - 1];
        for (int j = arr.size(); j > 0; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }

    for (auto it : arr)
    {
        cout << it << " ";
    }
}
void solution2(vector<int> arr, int k)
{
    k %= arr.size();
    reverse(arr.begin(), arr.end() - k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}

void move_zeros(vector<int> arr)
{
    int j = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    cout << "first zeorat :" << j;

    if (j == -1)
        return;

    for (int i = j + 1; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
}
int main()
{
    int values[] = {45192, 0, -659, -52359, -99225, -75991, 0, -15155, 27382, 59818, 0, -30645, -17025, 81209, 887, 64648};
    vector<int> arr;
    int size = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < size; i++)
    {
        arr.push_back(values[i]);
    }
    int K = 11939;
    move_zeros(arr);
}