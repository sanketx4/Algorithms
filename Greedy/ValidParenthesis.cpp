#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s)
{
    int left = 0;
    int right = 0;
    for (char ch : s)
    {
        if (ch == '(')
        {
            left++;
            right++;
        }
        else if (ch == ')')
        {
            left--;
            right--;
        }
        else
        {
            left--;
            right++;
        }
        if (right < 0)
            return false;
        if (left < 0)
            left = 0;
    }
    return left == 0;
}