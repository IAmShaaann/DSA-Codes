#include <iostream>
#include <string>
using namespace std;
bool solution(string str)
{
    // if we can assume that string is all lowercase letters.
    int hashmap[26] = {0}; // space_complexity - O(26) | (1)
    int count_odd = 0;
    for (int i = 0; i < str.size(); i++) // time_complexity - O(S)
    {
        hashmap[int(str[i] - 'a')]++;
    }
    for (auto it : hashmap) // time_complexity - O(26) | (1)
    {
        if (it % 2 != 0)
        {
            count_odd++;
        }
    }

    return count_odd > 1 ? false : true;
}

int main()
{
    string str = "tactcoa";
    cout << solution(str) << endl;
    return 0;
}