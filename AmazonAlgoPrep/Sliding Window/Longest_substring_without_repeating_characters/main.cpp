#include <iostream>
#include <string>
using namespace std;

/*

int brute_force(string str)
{
    vector<string> substrings = getSubstrings(str);
    int result = substringWithMaxLength(substrings);
    return result;
}
vector<string> getSubstrings(string str)
{
    vector<string> substring_vector;
    return substring_vector;
}
int substringWithMaxLenght(vector<string> substrings)
{
    int max_length_substring;
    return max_length_substring;
}
*/

int solution(string str)
{
    int max_length = 0;
    int low = 0;
    int high = 0;
    std::unordered_map<char, int> map;
    int distinct_characters = 0;

    while (high < str.size())
    {
        map[str[high]]++;
        distinct_characters = map.size();
        if (distinct_characters == high - low + 1)
        {
            max_length = max(max_length, high - low + 1);
            high++;
        }
        else
        {
            while (distinct_characters < high - low + 1)
            {
                map[str[low]]--;
                if (map[str[low]] == 0)
                {
                    map.erase(str[low]);
                }
                distinct_characters = map.size();
                low++;
            }
            high++;
        }
    }

    return max_length;
}
int main()
{
    string str = "pwwkew";
    cout << solution(str);
    return 0;
}