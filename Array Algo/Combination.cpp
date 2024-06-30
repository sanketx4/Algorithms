#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n)
{

    double res = 1;
    for (int i = 1; i <= n; i++)
        res = res * (m - n + i) / i;
    return (int)res;
}
