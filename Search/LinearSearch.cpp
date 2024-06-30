#include <bits/stdc++.h>
using namespace std;
int linearsearch(vector<int> &arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}