#include <iostream>
#include <string>
using namespace std;
bool solution(string s1, string s2)
{
    s2 = s2 + s2;
    bool isFound = s2.find(s1) != string::npos; //.find method uses O(N) time to execute.
    return isFound;
}
int main()
{
    string s1 = "watee4rbottles";
    string s2 = "erbottlewat";
    cout << solution(s1, s2);
    return 0;
}