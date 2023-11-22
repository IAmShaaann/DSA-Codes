#include <iostream>
#include <string>
using namespace std;
int solution(string str)
{
    int low = 0;
    int high = 0;
    int max_toys = 0;
    unordered_map<char, int> map;
    int distinct_toys = 0;
    while (high < str.size())
    {
        map[str[high]]++;
        distinct_toys = map.size();
        if (distinct_toys == 2)
        {
            max_toys = max(max_toys, high - low + 1);
            high++;
        }
        else
        {
            while (distinct_toys > 2)
            {
                map[str[low]]--;
                if (map[str[low]] == 0)
                {
                    map.erase(str[low]);
                }
                distinct_toys = map.size();
                low++;
            }
            high++;
        }
    }
    return max_toys;
}
int main()
{
    string str = "abaccab";
    cout << solution(str);
    return -1;
}