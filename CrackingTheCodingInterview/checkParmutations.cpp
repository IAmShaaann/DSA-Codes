// Question: Check if one string is parmutation of other. 
// Answer: Sort both stirngs if the end up being equal return true, else return false;
#include <bits/stdc++.h>
using namespace std;
bool check(string str1, string str2)
{
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if (str1 == str2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Answer: Check the freq of each char in both the strings, if the string are parmutation of each others, they will have same char freq,  

bool checkOptimised(string s1, string s2)
{
    int freq[128];
    char charArray[s1.size() + 1];
    strcpy(charArray, s1.c_str());
    for (auto it : s1)
    {
        freq[it]++;
    }

    for (int i = 0; i < s2.size(); i++)
    {
        int ch = s2[i];
        freq[ch]--;
        if (freq[ch] < 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string strTo = "PQRST";
    string strFrom = "STRPQ";
    cout << checkOptimised(strTo, strFrom);
    return 0;
}