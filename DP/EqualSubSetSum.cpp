//https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
#include <vector>

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        bool isSubsetSum(int n, vector<int> arr, int sum);
        int N = nums.size();
        long int sum = 0;

        for (int i = 0; i < N; i++)
        {
            sum = sum + nums[i];
        }
        if (sum % 2 != 0)
            return false;
        else
            return isSubsetSum(N, nums, sum / 2);
    }
};
bool isSubsetSum(int n, vector<int> arr, int sum)

{

    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)

    {

        for (int j = 0; j <= sum; j++)

        {

            if (!i)

                dp[i][j] = false;

            if (!j)

                dp[i][j] = true;
        }
    }

    for (int i = 1; i <= n; i++)

        for (int j = 1; j <= sum; j++)

            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] or dp[i - 1][j];

            else
                dp[i][j] = dp[i - 1][j];

    return dp[n][sum];
}