#include <iostream>
using namespace std;
int main()
{
    string s;
    long long cnt = 1;
    long long mx = 1;
    cin >> s;
    if (s.size() <= 1)
        mx = 1;

    for (size_t i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
            mx = max(mx, cnt);
        }
        else
        {
            cnt = 1;
        }
    }
    cout << mx;
}