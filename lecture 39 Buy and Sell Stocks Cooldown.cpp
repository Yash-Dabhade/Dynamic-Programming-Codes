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
        profit = max(values[ind] + func(ind + 2, 1, values, n, dp), func(ind + 1, 0, values, n, dp));
    }
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return func(0, 1, values, n, dp);
}




//Tabulation Time Complexity: O(N*2)  Space Complexity: O(N*2)

int stockProfit(vector<int> &values) {

    int n = values.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    dp[n][0] = dp[n][1] = 0;

    for (int ind = n - 1; ind >= 0; ind--) {
        int profit = 0;
        dp[ind][1]  = max(-values[ind] + dp[ind + 1][0], dp[ind + 1][1]);
        dp[ind][0] = max(values[ind] + dp[ind + 2][1], dp[ind + 1][0]);

    }


    return dp[0][1];
    // Write your code here.
}




//Space Optimization Time Complexity: O(N*2) Space Complexity: O(1)
int stockProfit(vector<int> &Arr)
{
    int n = Arr.size();
    vector<int> cur(2, 0);
    vector<int> front1(2, 0);
    vector<int> front2(2, 0);

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;

            if (buy == 0) { // We can buy the stock
                profit = max(0 + front1[0], -Arr[ind] + front1[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + front1[1], Arr[ind] + front2[0]);
            }

            cur[buy] = profit;
        }

        front2 = front1;
        front1 = cur;

    }

    return cur[0];
}
