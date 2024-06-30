#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    int ans = INT_MIN;
    for (auto i : nums)
    {
        sum += i;
        ans = max(ans, sum);
        if (sum < 0)
            sum = 0;
    }
    return ans;
}