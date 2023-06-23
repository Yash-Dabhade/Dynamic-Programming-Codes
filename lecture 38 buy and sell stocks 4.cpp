// https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698
#include <bits/stdc++.h>

//previous modification of stocks 3 Time Complexity: O(N*2*K) Space Complexity: O(K)
int maximumProfit(vector<int> &prices, int n, int k)
{

    vector<vector<int>> next(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));


    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
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

    return next[1][k];
}

