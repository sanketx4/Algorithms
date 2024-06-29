#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

static bool com(struct Item i1, struct Item i2)
{
    if (((double)i1.value / i1.weight) > ((double)i2.value / i2.weight))
        return true;
    if (((double)i1.value / i1.weight) < ((double)i2.value / i2.weight))
        return false;
    if (i1.weight <= i2.weight)
        return true;
    return false;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, com);
    int w = 0;
    double res = 0;
    int i = 0;
    while (i < n && (arr[i].weight + w) <= W)
    {
        res = res + (double)arr[i].value;
        w = w + arr[i].weight;
        i++;
    }
    if (i < n && w < W)
    {
        double fraction = ((double)arr[i].value / arr[i].weight);
        res = res + fraction * (double)(W - w);
    }
    return res;
}
