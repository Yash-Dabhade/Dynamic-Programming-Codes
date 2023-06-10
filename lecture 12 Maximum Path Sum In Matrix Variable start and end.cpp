// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998

//Memoization : Time Complexity: O(N*N) Space Complexity: O(N) + O(N*M)
#include <bits/stdc++.h>
int func(int i, int j, vector<vector<int>> &matrix, vector<vector<int>>&dp) {
	if (j < 0 || j >= matrix[0].size()) return -1e9;
	if (i == 0) return matrix[i][j];

	if (dp[i][j] != -1) return dp[i][j];

	int up = matrix[i][j] + func(i - 1, j, matrix, dp);
	int leftDiag = matrix[i][j] + func(i - 1, j - 1, matrix, dp);
	int rightDiag = matrix[i][j] + func(i - 1, j + 1, matrix, dp);

	return dp[i][j] = max(up, max(leftDiag, rightDiag));
}


int getMaxPathSum(vector<vector<int>> &matrix)
{
	int maxi = -1e9;
	int n = matrix.size();
	int m = matrix[0].size();

	vector<vector<int>> dp(n, vector<int>(m, -1));

	for (int j = 0; j < m; j++) {
		maxi = max(func(n - 1, j, matrix, dp), maxi);
	}
	return maxi;
}



//Tabulation Time Complexity: O(N*M)  Space Complexity: O(N*M)
int getMaxPathSum(vector<vector<int>> &matrix)
{
	int maxi = -1e9;
	int n = matrix.size();
	int m = matrix[0].size();

	vector<vector<int>> dp(n, vector<int>(m, 0));

	for (int j = 0; j < m; j++) dp[0][j] = matrix[0][j];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int up = -1e8, leftDiag = -1e8, rightDiag = -1e8;
			up = matrix[i][j] + dp[i - 1][j];
			if (j - 1 >= 0) leftDiag = matrix[i][j] + dp[i - 1][j - 1];
			if (j + 1 < m)  rightDiag = matrix[i][j] + dp[i - 1][j + 1];

			dp[i][j] = max(up, max(leftDiag, rightDiag));
		}
	}


	for (int j = 0; j < m; j++) {
		maxi = max(dp[n - 1][j], maxi);
	}
	return maxi;
}


//Space Optimization Time Complexity: O(N*M)  Space Complexity: O(M)
int getMaxPathSum(vector<vector<int>> &matrix)
{
	int maxi = -1e9;
	int n = matrix.size();
	int m = matrix[0].size();

	vector<int> prev(m, 0);

	for (int j = 0; j < m; j++) prev[j] = matrix[0][j];

	for (int i = 1; i < n; i++) {
		vector<int> curr(m, 0);
		for (int j = 0; j < m; j++) {
			int up = -1e8, leftDiag = -1e8, rightDiag = -1e8;
			up = matrix[i][j] + prev[j];
			if (j - 1 >= 0) leftDiag = matrix[i][j] + prev[j - 1];
			if (j + 1 < m)  rightDiag = matrix[i][j] + prev[j + 1];

			curr[j] = max(up, max(leftDiag, rightDiag));
		}
		prev = curr;
	}


	for (int j = 0; j < m; j++) {
		maxi = max(prev[j], maxi);
	}
	return maxi;
}