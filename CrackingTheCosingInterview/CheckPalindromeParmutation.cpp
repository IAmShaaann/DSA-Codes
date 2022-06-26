#include <bits/stdc++.h>
using namespace std;
bool checkPalindromeParmutation(string str)
{
    unordered_map<char, int> map;
    for (auto it : str)
    {
        map[it]++;
    }

    int evenCharCount = 0;
    for (auto it : map)
    {
        if (it.second % 2 != 0)
        {
            evenCharCount++;
        }
    }
    if (evenCharCount > 1)
    {
        return false;
    }
    else if (evenCharCount == 1)
    {
        if (str.size() % 2 == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}

int main()
{
    string str = "tactcoapapa";
    cout << checkPalindromeParmutation(str);
    return 0;
}