// https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207
#include <bits/stdc++.h>
//Tabulation Time Complexity: O(N*M) Space Complexity: O(N*M)
int lcs(string &str1, string &str2) {
	//	Write your code here.
	int n = str1.size(), m = str2.size(), ans = 0;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
				ans = max(dp[i][j], ans);
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	return ans;

}

//Space Optimization Time Complexity: O(N*M) Space Complexity: O(M)
#include <bits/stdc++.h>
int lcs(string &str1, string &str2) {
	//	Write your code here.
	int n = str1.size(), m = str2.size(), ans = 0;
	vector<int> prev(m + 1, 0), curr(m + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				curr[j] = 1 + prev[j - 1];
				ans = max(curr[j], ans);
			}
			else {
				curr[j] = 0;
			}
		}
		prev = curr;
	}
	return ans;

}