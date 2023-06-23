// https://www.codingninjas.com/codestudio/problems/buy-and-sell-stock_1071012
#include <bits/stdc++.h>

//memoization Time Complexity: O(N*2*3)  Space Complexity: O(N*2*3) + O(N)
int func(int ind, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp) {

    if (cap == 0 or ind == n) return 0;

    if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    int profit = 0;
    if (buy) {
        profit = max(-prices[ind] + func(ind + 1, 0, cap, prices, n, dp), func(ind + 1, 1, cap, prices, n, dp));
    }
    else {
        profit = max(prices[ind] + func(ind + 1, 1, cap - 1, prices, n, dp), func(ind + 1, 0, cap, prices, n, dp));
    }
    return dp[ind][buy][cap] = profit;
}

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return func(0, 1, 2, prices, n, dp);
}


//Tabulation Time Complexity: O(N*2*3)  Space Complexity: O(N*2*3)
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[ind] + dp[ind + 1][0][cap], dp[ind + 1][1][cap]);
                }
                else {
                    profit = max(prices[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
                }
                dp[ind][buy][cap] = profit;
            }
        }
    }

    return dp[0][1][2];
}



//Space Optimized Solution  Time Complexity: O(N*2*3)  Space Complexity: O(1)

int maxProfit(vector<int>& prices, int n)
{
    vector<vector<int>> next(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));


    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[ind] + next[0][cap], next[1][cap]);
                }
                else {
                    profit = max(prices[ind] + next[1][cap - 1], next[0][cap]);
                }
                curr[buy][cap] = profit;
            }
        }
        next = curr;
    }

    return next[1][2];
}