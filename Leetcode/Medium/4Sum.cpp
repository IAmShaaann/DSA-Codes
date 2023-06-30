#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;

// Solution 1: Without unique quads.
// int BS(int low, int high , int target, vector<int> arr){
//     int mid = low + (high -low) /2;
//     if( arr[mid] > target){
//         high = low - 1;
//     }else if(arr[mid] < target){
//         low = high + 1;
//     }else{
//         return mid;
//     }
//     return -1;
// }
// vector<vector<int>> solution(vector<int> arr, int target){
//     sort(arr.begin(), arr.end());
//     for(int i = 0;i<arr.size();i++){
//         for( int j = i + 1;j<arr.size();j++){
//             for(int k = j+ 1;k<arr.size();k++){
//                 int findTarget = arr[i] + arr[j] + arr[k];
//                 int d = BS(k+1, arr.size(), target - findTarget, arr);
//                 if(d != -1){
//                     vector<int> temp;
//                     temp.push_back(arr[i]);
//                     temp.push_back(arr[j]);
//                     temp.push_back(arr[k]);
//                     temp.push_back(arr[d]);
//                     ans.push_back(temp);
//                 }
//             }
//         }
//     }
//     return ans ;
// }

// Solution 2:
void twoSum(int low, int high, vector<int> arr, int target)
{
    int a = arr[low - 1];
    int b = arr[low - 2];
    while (low < high)
    {
        cout<<arr[low]<<endl;
        if (arr[low] + arr[high] < target)
        {
            low++;
        }
        else if (arr[low] + arr[high] > target)
        {
            high--;
        }
        else if(arr[low] + arr[high] == target )
        {
            cout<<"Found something"<<endl;
            vector<int> temp;
            temp.push_back(a);

            temp.push_back(b);

            temp.push_back(arr[low]);
            temp.push_back(arr[high]);
            ans.push_back(temp);
            // skip duplicate b
            while (low < high and arr[low] == arr[low + 1])
                low++;
            while (low < high and arr[high] == arr[high - 1])
                high--;

            low++;
            high--;
        }
    }
}
vector<vector<int>> solution(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {

            int findTarget = target - arr[i] - arr[j];
            twoSum(j + 1, arr.size() - 1, arr, findTarget);
            while(j+1< arr.size() and arr[j+1] == arr[j])j++;
        }
        while(i+1<arr.size() and arr[i+1] == arr[i]) i++; 
    }

    return ans;
}

int main()
{
    vector<int> arr = {2,2,2,2,2};
    vector<vector<int>> ans = solution(arr, 8);
    for (auto row : ans)
    {
        for (auto ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}