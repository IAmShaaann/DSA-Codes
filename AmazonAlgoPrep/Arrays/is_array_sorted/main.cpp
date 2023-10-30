#include <iostream>
using namespace std;
bool is_rotated(vector<int> arr)
{
    vector<int> double_vector(0);
    for (auto it : arr)
    {
        double_vector.push_back(it);
    }
    for (auto it : arr)
    {
        double_vector.push_back(it);
    }
}
bool solution(vector<int> arr)
{
    // sort(arr.begin(), arr.end());
    bool rotated = is_rotated(arr);
    // bool sorted = is_sorted(arr);
}
int main()
{
    std::vector<int> arr;

    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(2);
    cout << solution(arr);
    return 0;
}