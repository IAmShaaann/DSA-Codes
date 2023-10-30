#include <iostream>
#include <string>
#include <vector>
using namespace std;
string solution(string str)
{
    int consecutive_count = 1;
    string compressed = "";              // space_complexity - O(1)
    for (int i = 0; i < str.size(); i++) // time_complexity - O(S)
    {
        if (str[i] == str[i + 1])
        {
            consecutive_count++;
        }
        else
        {

            string temp = str[i] + to_string(consecutive_count);
            compressed += temp;
            consecutive_count = 1;
            temp = "";
        }
    }
    return compressed.size() > str.size() ? str : compressed;
}
int main()
{
    string str = "aavvvvddddssssjjjjfffkkkdddkksssoooeeennnssskkkccckkkssskkksss";
    string str2 = "qwertyuiopolkjhgfdsazxcvbnm";
    string res = solution(str2);
    cout << res;
    return 0;
}