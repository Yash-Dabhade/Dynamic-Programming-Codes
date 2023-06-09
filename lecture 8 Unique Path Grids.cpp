#include<bits/stdc++.h>
using namespace std;

//Memoization =  Time Complexity: O(M*N), Time Complexity: O(M*N)

int countWaysUtil(int i, int j, vector<vector<int>> &dp) {
	if (i == 0 and j == 0) return 1;
	if (i < 0 or j < 0) return -1;

	if (dp[i][j] != -1) return dp[i][j];

	int up = countWaysUtil(i - 1, j, dp);
	int left = countWaysUtil(i, j - 1, dp);

	return dp[i][j] = up + left;
}

int countWays(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return countWaysUtil(m - 1, n - 1, dp);
}

int main() {
	int m = 3;
	n = 2;
	cout << countWays(m, n);
}


//Tabulation =  Time Complexity: O(M*N), Time Complexity: O(M*N)

int countWaysUtil(int m, int n, vector<vector<int>> &dp) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 and j == 0) {
				dp[i][j] == 1;
				continue;
			}

			int up = 0, left = 0;

			if (i > 0) up = dp[i - 1][j];
			if (j > 0) left = dp[i][j - 1];

			dp[i][j] = up + left;
		}
	}
	return dp[m - 1][n - 1];
}

int countWays(int m, int n) {
	vector<vector<int> > dp(m, vector<int>(n, -1));
	return countWaysUtil(m, n, dp);

}


//Space Optimization = Time Complexity :O(M*N) , Space Complexity:O(N)

int countWays(int m, int n) {
	vector<int> prev(n, 0);
	for (int i = 0; i < m; i++) {
		vector<int> curr(n, 0);
		for (int j = 0; j < n; j++) {
			if (i == 0 and j == 0) {
				curr[j] = 1;
			}
			int up = 0, left = 0;
			if (i > 0) up = prev[j];
			if (j > 0) left = prev[j - 1];

			curr[j] = up + left;
		}
		prev = curr;
	}
}


int main() {

	int m = 3;
	int n = 2;

	cout << countWays(m, n);
}


