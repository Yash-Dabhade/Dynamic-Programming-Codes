// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542
#include <bits/stdc++.h>

// Memoization :
int func(int ind, vector<int> weight, vector<int> value, int n, int W, vector<vector<int>> &dp) {
	if (ind == 0) {
		if (weight[0] <= W) return value[0];
		else return 0;
	}

	if (dp[ind][W] != -1) return dp[ind][W];

	int notTake = 0 + func(ind - 1, weight, value, n, W, dp);
	int take = INT_MIN;

	if (weight[ind] <= W) take = value[ind] + func(ind - 1, weight, value, n, W - weight[ind], dp);

	return dp[ind][W] = max(take, notTake);
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
	return func(n - 1, weight, value, n, maxWeight, dp);
}


// Tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

	for (int W = weight[0]; W <= maxWeight; W++) {
		dp[0][W] = value[0];
	}

	for (int ind = 1; ind < n; ind++) {
		for (int W = 0; W <= maxWeight; W++) {
			int notTake = 0 + dp[ind - 1][W];
			int take = INT_MIN;

			if (weight[ind] <= W) take = value[ind] + dp[ind - 1][W - weight[ind]];

			dp[ind][W] = max(take, notTake);
		}
	}

	return dp[n - 1][maxWeight];

}


//Space Optimization 2 array
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);

	for (int W = weight[0]; W <= maxWeight; W++) {
		prev[W] = value[0];
	}

	for (int ind = 1; ind < n; ind++) {
		for (int W = 0; W <= maxWeight; W++) {
			int notTake = 0 + prev[W];
			int take = INT_MIN;

			if (weight[ind] <= W) take = value[ind] + prev[W - weight[ind]];

			curr[W] = max(take, notTake);
		}
		prev = curr;
	}

	return prev[maxWeight];

}


//Space Optimzation 1 array
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	vector<int> prev(maxWeight + 1, 0);

	for (int W = weight[0]; W <= maxWeight; W++) {
		prev[W] = value[0];
	}

	for (int ind = 1; ind < n; ind++) {
		for (int W = maxWeight; W >= 0; W--) {
			int notTake = 0 + prev[W];
			int take = INT_MIN;

			if (weight[ind] <= W) take = value[ind] + prev[W - weight[ind]];

			prev[W] = max(take, notTake);
		}
	}

	return prev[maxWeight];

}


