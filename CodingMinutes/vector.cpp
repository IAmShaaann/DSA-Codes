#include <bits/stdc++.h>
using namespace std;
void print(vector<int> arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    print(arr);
    arr.push_back(60); // insert value at the end of the array;
    print(arr);
    arr.pop_back(); // removes value from the end of the array;
    print(arr);
    cout << arr.capacity() << endl; // returns the capacity of a vector.
    arr.shrink_to_fit();            // removes the extra space allocated by the vector.
    auto it = arr.begin();
    arr.insert(it + 3, 1, 5);
    print(arr);
    arr.erase(it + 2, it + 4);
    print(arr);

    // 2D vector

    vector<vector<int>> matrix = { {10, 20, 30, 40},
                                   {69, 96, 85},
                                   {75, 89, 96, 54, 52},
                                   {50, 45} };
                                
    cout<<"2D Vector: "<<endl;
    for(auto it: matrix){
        for( auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    cout<<matrix.capacity()<<endl;
}