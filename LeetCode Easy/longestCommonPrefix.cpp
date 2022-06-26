/*
Question: Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Solution:  Now we  take the first word and compare it with the rest of the words in the list.if c[index] == strs[i][index] that means all the words in the string have at least one letter common in them. and we add that into the lcp, and if we break this loop then wereturn whaterver value we have in the lcp variable.

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // error checking
        string longestCommonPrefix = "";
        if (strs.size() == 0)
        { // if no element is there, return empty string.
            return longestCommonPrefix;
        }
        int index = 0;

        for (auto c : strs[0])
        {
            for (int i = 1; i < strs.size(); i++)
            {
                if (index >= strs[i].size() or c != strs[i][index])
                {
                    return longestCommonPrefix;
                }
            }
            longestCommonPrefix += c;
            index++;
        }
        return longestCommonPrefix;
    }
};
