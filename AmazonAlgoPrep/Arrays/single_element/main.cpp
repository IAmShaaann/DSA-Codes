#include <iostream>
#include <vector>
using namespace std;
void solution(vector<int> arr)
{
    int xorr = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xorr = xorr ^ arr[i];
        cout << "xor: " << xorr << endl;
    }
    cout << xorr;
}

int main()
{
    int arr1[] = {4, 1, 2, 1, 2};
    vector<int> vec1;

    for (int i = 0; i < 5; i++)
    {
        vec1.push_back(arr1[i]);
    }
    solution(vec1);
}