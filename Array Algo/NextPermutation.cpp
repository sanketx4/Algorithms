#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    for (i = n - 1; i > 0; i--)
    {
        if (nums[i - 1] < nums[i])
        {
            break;
        }
    }
    if (i == 0)
    {
        reverse(begin(nums), end(nums));
        return;
    }
    for (int j = n - 1; j > 0; j--)
    {
        if (nums[j] > nums[i - 1])
        {
            swap(nums[i - 1], nums[j]);
            break;
        }
    }
    reverse(nums.begin() + i, nums.end());
}