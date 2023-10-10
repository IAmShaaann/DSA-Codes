#include <iostream>
#include <string>
using namespace std;
bool bruteforce(string str1, string str2)
{
    // time_complexity = O(N log N) space_complexity O(1)
    if (str1.size() != str2.size())
        return -1;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1 == str2;
}

bool better(string str1, string str2)
{
    // time_complexity = O(str1 | str2) space_complexity = O (128) | O(1)
    if (str1.size() != str2.size())
        return -1;

    int hashmap[128] = {0};

    for (int i = 0; i < str1.size(); i++)
    {
        hashmap[str1[i]]++;
    }

    for (int i = 0; i < str2.size(); i++)
    {
        hashmap[str2[i]]--;
        if (hashmap[str2[i]] < 0)
        {
            return 0;
        }
    }
    return true;
}

int main()
{
    string str1 = "qwertyuiopasdfghjklzxcvbnm";
    string str2 = "mnbvcxaasdfghjklpoiuytrewq";
    cout << bruteforce(str1, str2);
    cout << better(str1, str2);

    return 0;
}