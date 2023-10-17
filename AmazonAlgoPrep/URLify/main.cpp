#include <iostream>
#include <string>
using namespace std;

string solution(string str, int size)
{

    int space_count = 0;
    int new_size = 0;
    for (int i = 0; i < size; i++) // O(1) as the size is given.
    {
        if (str[i] == ' ')
        {
            space_count++;
        }
    }
    new_size = size + (2 * space_count);
    cout << new_size << endl;

    for (int i = size - 1, j = new_size - 1; i >= 0; i--)
    {
        cout << str[i] << str[j] << str << endl;
        if (str[i] == ' ')
        {
            str[j] = '0';
            str[j - 1] = '2';
            str[j - 2] = '%';
            j -= 3;
        }
        else
        {
            str[j] = str[i];
            j--;
        }
    }
    cout << str << ' ' << endl;
    return str;
}

int main()
{
    string str = "Mr John Smith is doing an amazing job working for google";
    int true_length = 56;
    cout << true_length << endl;
    string result = solution(str, true_length);
    cout << result << endl;
    return 0;
}
