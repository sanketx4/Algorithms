#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    long long N = abs(n);
    double num = x;
    double res = 1.0;
    while (N)
    {
        if (N % 2)
            res = res * num;
        num = num * num;
        N /= 2;
    }
    if (n < 0)
        res = 1 / res;
    return res;
}