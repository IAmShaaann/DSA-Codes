#include <bits/stdc++.h>
using namespace std;
vector<int> sortBrute(vector<int> arr)
{
    vector<int> ans;
    int countZero = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            countZero++;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (countZero > 0)
        {
            ans.push_back(0);
            countZero--;
        }
        else
        {
            ans.push_back(1);
        }
    }
    return ans;
}
vector<int> sortOptimised(vector<int> arr){
    vector<int> ans(arr.size());
    int k = 0;
    for(int i =0 ;i<arr.size();i++){
        if(arr[i] == 0){
            ans[k] = 0;
            k++;
        }
    }
    for(int i = k; i<arr.size();i++){
        ans[k] = 1;
        k++;
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 0, 1, 0, 1, 0, 0, 1};
    vector<int> ans = sortOptimised(arr);
    for(auto i : ans){
        cout<<i<<" ";
    }
}

