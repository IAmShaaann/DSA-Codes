#include <iostream>
#include <vector>
using namespace std;
void solution(vector<int> arr)
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
    solution(arr);
}