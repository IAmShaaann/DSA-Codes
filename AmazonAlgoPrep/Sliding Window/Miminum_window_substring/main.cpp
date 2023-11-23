#include <iostream>
#include <string>
using namespace std;
int solution(string str, string s2)
{
    int low = 0;
    int high = 0;
    int max_length = INT_MAX;
    unordered_map<char, int> map;
    string res = "";

    for (int i = 0; i < s2.size(); i++)
    {
        map[s2[i]]++;
    }
    int values_needed = map.size();
    int string_start = 0;

    while (high < str.size())
    {
        if (map.find(str[high]) != map.end())
        {
            map[str[high]]--;
            if (map[str[high]] == 0)
                values_needed--;
        }
        if (values_needed == 0)
        {
            while (values_needed == 0)
            {
                if (map.find(str[low]) != map.end())
                {
                    map[str[low]]++;
                    if (map[str[low]] == 1)
                    {
                        values_needed++;
                        if (high - low + 1 < max_length)
                        {
                            string_start = low;
                            max_length = high - low + 1;
                        }
                    }
                }
                low++;
            }
        }
        high++;
    }
    cout << str.substr(string_start, string_start + max_length);
    if (minlen == INT_MAX)
        return "";
    return max_length;
}
int main()
{
    string s1 = "a";
    string s2 = "b";
    cout << solution(s1, s2);
    return 0;
}