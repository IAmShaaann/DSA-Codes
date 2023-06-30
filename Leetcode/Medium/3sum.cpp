#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void twoSum(int low, int high, vector<int> arr, int target){
    int a = arr[low-1];
    while(low<high){
        if(arr[low] + arr[high] < target){
            low++;
        }else if(arr[low] + arr[high] > target){
            high --;
        }else{
            vector<int> temp;
            temp.push_back(a);
            temp.push_back(arr[low]);
            temp.push_back(arr[high]);
            ans.push_back(temp);
            //skip duplicate b
            while(low<high and arr[low] == arr[low+1]) low++;
            while(low<high and arr[high] == arr[high-1]) high--;

            low++;
            high--; 
        }
    }
    
}
vector<vector<int>> solution(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        // a+ b + c = 0 -> b + c = a - 0;
        if (i == 0 || arr[i - 1] != arr[i])
        {
            twoSum(i + 1, arr.size()-1, arr, 0 - arr[i]); // initial index, final index, array, target
        }
    }
    return ans ;
}
int main()
{ 
    vector<vector<int>> ans = solution(arr);
    for (auto it : ans)
    {
        for (auto item : it)
        {
            cout << item << " ";
        }
    }
}