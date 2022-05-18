/*
Question: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
*/

#include <bits/stdc++.h>
using namespace std;
bool matching(char a, char b)
{
    return ((a == '(' and b == ')') or (a == '{' and b == '}') or (a == '[' and b == ']'));
}
bool solution(string str)
{
    stack<char> stack;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '{' or str[i] == '[' or str[i] == '(')
        {
            stack.push(str[i]); // push the opening braces.
        }
        else
        { // closing braces
            if (stack.empty())
            { // we have some more elements,
                return false;
            }
            else if (!matching(stack.top(), str[i]))
            {
                return false;
            }
            else
            {
                stack.pop();
            }
        }
    }
    return stack.empty() ? true : false;
}
int main()
{
    string str = "{[{{{{]}}}}}((()))()(){}{}{}[][][]";
    cout << solution(str);
    return 0;
}