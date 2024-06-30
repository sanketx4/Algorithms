#include <bits/stdc++.h>
using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> res;
    for (int i = 0; i <= rowIndex; i++)
    {
        res.push_back(1);
        for (int j = i - 1; j >= 1; --j)
            res[j] = res[j] + res[j - 1];
    }
    return res;
}