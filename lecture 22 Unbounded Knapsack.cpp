// https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029
#include <bits/stdc++.h>

//Memoization Time Complexity: O(N*W) Space Complexity: O(N*W) + O(N)
int func(int ind, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {
    if (ind == 0) {
        return (int)(w / weight[0]) * profit[0];
    }

    if (dp[ind][w] != -1) return dp[ind][w];

    int notTake = func(ind - 1, w, profit, weight, dp);
    int take = INT_MIN;
    if (weight[ind] <= w) take = profit[ind] + func(ind, w - weight[ind], profit, weight, dp);

    return dp[ind][w] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return func(n - 1, w, profit, weight, dp);
}


//Tabulation Time Complexity: O(N*W) Space Complexity: O(N*W)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    for (int W = 0; W <= w; W++) {
        dp[0][W] = (W / weight[0]) * profit[0];
    }

    for (int ind = 1; ind < n; ind++) {
        for (int W = 0; W <= w; W++) {
            int notTake = dp[ind - 1][W];
            int take = INT_MIN;
            if (weight[ind] <= W) take = profit[ind] + dp[ind][W - weight[ind]];

            dp[ind][W] = max(take, notTake);
        }
    }

    return dp[n - 1][w];

    return func(n - 1, w, profit, weight, dp);
}

//Space optimization Time Complexity: O(N*W) Space Complexity: O(W)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0), curr(w + 1, 0);

    for (int W = 0; W <= w; W++) {
        prev[W] = (W / weight[0]) * profit[0];
    }

    for (int ind = 1; ind < n; ind++) {
        for (int W = 0; W <= w; W++) {
            int notTake = prev[W];
            int take = INT_MIN;
            if (weight[ind] <= W) take = profit[ind] + curr[W - weight[ind]];

            curr[W] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[w];
}


