// https://www.codingninjas.com/codestudio/problems/triangle_1229398
#include <bits/stdc++.h>

//memoization TC: O(N*N)  SC: O(N) + O(N*N)
int func(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>> &dp) {
	if (i == n - 1) {
		return triangle[i][j];
	}
	if (dp[i][j] != -1) return dp[i][j];
	int d = triangle[i][j] + func(i + 1, j, triangle, n, dp);
	int dg = triangle[i][j] + func(i + 1, j + 1, triangle, n, dp);
	return dp[i][j] = min(d, dg);
}

int minimumPathSum(vector<vector<int>>& triangle, int n) {
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return func(0, 0, triangle, n, dp);
}



//tabulation  Time Complexity: O(N*N) , Space Complexity: O(N*N)
int minimumPathSum(vector<vector<int>>& triangle, int n) {
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for (int j = 0; j < n; j++) {
		dp[n - 1][j] = triangle[n - 1][j];
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			int d = triangle[i][j] + dp[i + 1][j];
			int dg = triangle[i][j] + dp[i + 1][j + 1];

			dp[i][j] = min(d, dg);
		}
	}
	return dp[0][0];
}


//space optimization Time Complexity: O(N*N)  Space Complexity: O(N)
int minimumPathSum(vector<vector<int>>& triangle, int n) {
	// Write your code here.
	vector<int> front(n, 0);
	for (int j = 0; j < n; j++) {
		front[j] = triangle[n - 1][j];
	}

	for (int i = n - 2; i >= 0; i--) {
		vector<int> curr(n, 0);
		for (int j = i; j >= 0; j--) {
			int d = triangle[i][j] + front[j];
			int dg = triangle[i][j] + front[j + 1];

			curr[j] = min(d, dg);
		}
		front = curr;
	}
	return front[0];
}