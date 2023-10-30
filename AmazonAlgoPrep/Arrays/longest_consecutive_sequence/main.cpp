#include <iostream>
#include <vector>
using namespace std;

int brute_force(vector<int> arr)
{
    int max_cnt = 0;
    int searched_value;
    for (int i = 0; i < arr.size(); i++)
    {
        searched_value = arr[i] + 1;
        int cnt = 1;
        for (int j = 0; j < arr.size(); j++)
        {

            if (arr[j] == searched_value)
            {
                cnt++;
                searched_value = arr[j] + 1;
            }
        }
        max_cnt = max(cnt, max_cnt);
        cnt = 0;
    }
    return max_cnt;
}

int better(vector<int> arr)
{
    if (arr.size() == 0)
        return -1;
    sort(arr.begin(), arr.end());
    int smallestSoFar = INT_MIN;
    int cnt = 0;
    int maxCnt = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] - 1 == smallestSoFar)
        {
            cnt += 1;
            smallestSoFar = arr[i];
        }
        else if (arr[i] != smallestSoFar)
        {
            cnt = 1;
            smallestSoFar = arr[i];
        }
        maxCnt = max(cnt, maxCnt);
    }
    return maxCnt;
}

int solution(vector<int> arr)
{
    int longest = 1;
    unordered_set<int> st;
    int n = arr.size();
    if (n == 0)
        return 0;

    for (auto it : arr)
    {
        st.insert(it);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int current = it;
            while (st.find(current + 1) != st.end())
            {
                current = current + 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main()
{

    int arr[] = {
        21, 15, 6, 2, 1, 16, 4, 2, 29, 9, 12, 8, 5, 14, 21, 8, 12, 17, 16, 6, 26, 3};
    vector<int> vec;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        vec.push_back(arr[i]);
    }
    cout << solution(vec);

    return 0;
}