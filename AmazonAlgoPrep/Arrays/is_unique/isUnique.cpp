#include <iostream>
#include <string>
using namespace std;
bool better(string str)

{
    // time_complexity = O(N) space_complexity = O(128) | O(1)
    if (str.size() > 128)
        return -1;

    bool hashmap[128] = {false};

    for (int i = 0; i < str.size(); i++)
    {
        if (hashmap[str[i]])
        {
            return false;
        }
        hashmap[str[i]] = true;
    }
    return true;
}

bool bruteforce(string arr)
{

    // time_complexity = O(N^2) space_complexity = O(1)

    for (int i = 0; i < arr.size(); i++)
    {

        int counter = 0;

        for (int j = 0; j < arr.size(); j++)
        {

            if (arr[i] == arr[j])

                counter++;

            if (counter > 1)

                return false;
        }

        counter = 0;
    }
    return true;
}

int main()
{
    string str = "qazxcvbnmlkjhgfdswertyuiopz";
    cout << better(str);
    cout << bruteforce(str);
}
