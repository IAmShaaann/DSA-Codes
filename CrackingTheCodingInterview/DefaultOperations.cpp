// Given 2 strings, can you make both string equal with either one of these opertions: Insert, Delete, Edit
#include <bits/stdc++.h>
using namespace std;
bool oneEditAway(string s1, string s2)
{
    int differentCount = 0;
    int i = 0, j = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            differentCount++;
        }
        if (differentCount > 1)
        {
            return false;
        }
    }
    return true;
}
bool oneInsertAway(string s1, string s2)
{
    int i = 0, j = 0;
    while (i < s1.size() and j < s2.size())
    {
        if (s1[i] != s2[j])
        {
            if (i != j)
            {
                return false;
            }
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    return true;
}
bool checkStringPossible(string s1, string s2)
{
    if (s1.size() == s2.size())
    {
        // cout << "Called Edit";
        return oneEditAway(s1, s2);
    }
    else if (s1.size() + 1 == s2.size())
    {
        // cout << "Called insert 1";
        return oneInsertAway(s1, s2);
    }
    else if (s1.size() - 1 == s2.size())
    {
        // cout << "Called insert 2";
        return oneInsertAway(s1, s2);
    }
}

bool solution(string s1, string s2)
{
    return checkStringPossible(s1, s2);
}
int main()
{
    string s1 = "pale";
    string s2 = "bae";
    cout << solution(s1, s2);

    return 0;
}