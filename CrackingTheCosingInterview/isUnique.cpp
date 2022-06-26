// Question: Check if the string contians all the unique characters.
// Answer: Check for each char everytime in the string.

#include <bits/stdc++.h>
using namespace std;
bool isUnique(string str)
{
    int count = 0;
    char ch;
    for (int i = 0; i < str.size(); i++)
    {
        ch = str[i];
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == ch)
            {
                count++;
            }
            // cout<<count << " @ " << ch<<endl;
            if (count > 1)
            {
                return false;
            }
        }
        count = 0;
    }
    return true;
}

// basically calculate the freq of all the characters in the stirng if any char has freq greater than 1 return false, else return true;
bool isUniqueOptimised(string str)
{
    bool freq[128] = {false};
    for (int i = 0; i < str.size(); i++)
    {
        int val = str[i];
        if (freq[val])
        {
            return false;
        }
        freq[val] = true;
    }
    return true;
}

int main()

{
    string str = "abcbdadbcd";
    string unique = "abcdefghijklmnopqrstuvwxyz";
    cout << isUniqueOptimised(str);
    cout << isUniqueOptimised(unique);
    return 0;
}