#include <iostream>
#include <string>
#include <vector>
using namespace std;
int solution(string str, int k)
{
    int answer = 0;
    int i = 0;
    int j = 1;
    unordered_map<char, int> map;
    map[str[0]]++;
    int map_size = map.size();
    while (j < str.length())
    {
        map[str[j]]++;
        map_size = map.size();

        if (map_size < k)
        {
            j++;
        }
        else if (map_size == k)
        {
            answer = max(answer, j - i + 1);
            j++;
        }
        else if (map_size > k)
        {
            while (map_size > k)
            {
                map[str[i]]--;
                if (map[str[i]] == 0)
                {
                    map.erase(str[i]);
                }
                i++;
                map_size = map.size();
            }
            j++;
        }
    }
    return answer;
}
int main()
{

    string str = "aabacbebebe";

    cout << solution(str, 3);
    return 0;
}