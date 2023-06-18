// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284
#include<bits/stdc++.h>

//Memoization : Time Complexity: O(N*N) Space Complexity: O(N*N) + O(N)
int func(int ind, int n, vector<int> &price, vector<vector<int>> &dp) {
	if (ind == 0) {
		return n * price[0];
	}

	if (dp[ind][n] != -1) return dp[ind][n];

	int notTake = func(ind - 1, n, price, dp);
	int take = INT_MIN;
	int rodSize = ind + 1;
	if (rodSize <= n) take = price[ind] + func(ind, n - rodSize, price, dp);

	return dp[ind][n] = max(notTake, take);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n + 1, -1));
	return func(n - 1, n, price, dp);
}





//Tabulation: Time Complexity: O(N*N) Space Complexity: O(N*N)
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n + 1, 0));
	for (int i = 0; i <= n; i++) {
		dp[0][i] = i * price[0];
	}

	for (int ind = 1; ind < n; ind++) {
		for (int N = 0; N <= n; N++) {
			int notTake = dp[ind - 1][N];
			int take = INT_MIN;
			int rodSize = ind + 1;
			if (rodSize <= N) take = price[ind] + dp[ind][N - rodSize];

			dp[ind][N] = max(notTake, take);
		}
	}

	return dp[n - 1][n];

}



//Space Optimized: Time Complexity: O(N*N) Space Complexity: O(2*N)
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> prev(n + 1, 0), curr(n + 1, 0);

	for (int i = 0; i <= n; i++) {
		prev[i] = i * price[0];
	}

	for (int ind = 1; ind < n; ind++) {
		for (int N = 0; N <= n; N++) {
			int notTake = prev[N];
			int take = INT_MIN;
			int rodSize = ind + 1;
			if (rodSize <= N) take = price[ind] + curr[N - rodSize];

			curr[N] = max(notTake, take);
		}
		prev = curr;
	}

	return prev[n];

}


//Space Optimized: Time Complexity: O(N*N) Space Complexity: O(N)
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> prev(n + 1, 0);

	for (int i = 0; i <= n; i++) {
		prev[i] = i * price[0];
	}

	for (int ind = 1; ind < n; ind++) {
		for (int N = 0; N <= n; N++) {
			int notTake = prev[N];
			int take = INT_MIN;
			int rodSize = ind + 1;
			if (rodSize <= N) take = price[ind] + prev[N - rodSize];

			prev[N] = max(notTake, take);
		}
	}

	return prev[n];

}

