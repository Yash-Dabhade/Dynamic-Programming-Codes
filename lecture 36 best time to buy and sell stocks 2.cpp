// https://www.codingninjas.com/codestudio/problems/selling-stock_630282
#include<bits/stdc++.h>


//Memoization Time Complexity: O(N*2)  Space Complexity: O(N*2) + O(N)
long func(long ind, long buy, long *values, int n, vector<vector<long>> &dp) {
    if (ind == n) return 0;

    long profit = 0;

    if (dp[ind][buy] != -1) return dp[ind][buy];

    if (buy) {
        profit = max(-values[ind] + func(ind + 1, 0, values, n, dp), func(ind + 1, 1, values, n, dp));
    }
    else {
        profit = max(values[ind] + func(ind + 1, 1, values, n, dp), func(ind + 1, 0, values, n, dp));
    }
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return func(0, 1, values, n, dp);
}




//Tabulation Time Complexity: O(N*2)  Space Complexity: O(N*2)
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));

    dp[n][0] = dp[n][1] = 0;

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            long profit = 0;

            if (buy) {
                profit = max(-values[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            }
            else {
                profit = max(values[ind] + dp[ind + 1][1], dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }


    return dp[0][1];
}


//Space Optimization Time Complexity: O(N*2) Space Complexity: O(1)
long getMaximumProfit(long *values, int n)
{
    vector<long> next(2, 0), curr(2, 0);

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            long profit = 0;

            if (buy) {
                profit = max(-values[ind] + next[0], next[1]);
            }
            else {
                profit = max(values[ind] + next[1], next[0]);
            }
            curr[buy] = profit;
        }
        next = curr;
    }

    return curr[1];
}