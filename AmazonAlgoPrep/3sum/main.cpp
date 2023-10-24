#include <iostream>
#include <vector>
using namespace std;
// void brute_force(vector<int> arr)
// {
//     vector<vector<int>> res;
//     int n = arr.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             for (int k = 0; k < n; k++)
//             {
//                 if (arr[i] + arr[j] + arr[k] == 0)
//                 {
//                     vector<int> subvec;
//                     subvec.push_back(arr[i]);
//                     subvec.push_back(arr[j]);
//                     subvec.push_back(arr[k]);
//                     res.push_back(subvec);
//                 }
//             }
//         }
//     }
// }

void better(vector<int> arr)
{
    set<vector<int>> st;

    unordered_map<int, int> map;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int different = -(arr[i] + arr[j]);
            if (map.find(different) != map.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                st.insert(temp);
            }
            map[different] = i;
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

void solution(vector<int> arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1;
        int k = arr.size() - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

int main()
{
    int arr[] = {2, 6, 5, 8, 11};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    solution(vec);
    return 0;
}
