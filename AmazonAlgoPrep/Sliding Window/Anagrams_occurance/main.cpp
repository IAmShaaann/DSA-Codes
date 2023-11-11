#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> get_parmutations(string str, int K)
{
    vector<string> res;
    return res;
}
int brute_force(string bigger, string smaller)
{
    int size_smaller = smaller.size();
    int anagram_count = 0;

    vector<string> bigger_parms;
    vector<string> smaller_perms;

    smaller_perms = get_parmutations(smaller, size_smaller);
    bigger_parms = get_parmutations(bigger, size_smaller);

    for (int i = 0; i < bigger_parms.size(); i++)
    {
        for (int j = 0; j < smaller_perms.size(); j++)
        {
            if (bigger_parms[i] == smaller_perms[j])
            {
                anagram_count++;
            }
        }
    }

    return anagram_count;
}

int solution(string str, string pattern)
{
    int cnt = 0;
    int window = pattern.size();
    int start = 0;
    int end = 0;
    unordered_map<int, int> pattern_map;

    for (int i = 0; i < pattern.size(); i++)
        pattern_map[pattern[i]]++;
    int distinct_values = pattern_map.size();

    while (start + window <= str.size())
    {
        char left_behind = str[start];
        char new_added = str[end];

        if (end - start < window)
        {
            pattern_map[new_added]--;
            if (pattern_map[new_added] == 0)
                distinct_values--;

            if (distinct_values == 0)
                cnt++;

            end++;
        }
        else if (end - start == window)
        {

            pattern_map[left_behind]++;
            if (pattern_map[left_behind] == 1)
                distinct_values++;

            pattern_map[new_added]--;
            if (pattern_map[new_added] == 0)
                distinct_values--;

            if (distinct_values == 0)
                cnt++;

            start++;
            end++;
        }
    }
    return cnt;
}

int main()
{
    string str1 = "forxxorfxdofr";
    string str2 = "for";
    cout << solution(str1, str2);
}