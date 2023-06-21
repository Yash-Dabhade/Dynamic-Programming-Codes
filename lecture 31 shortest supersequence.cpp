#include <bits/stdc++.h>
// https://www.codingninjas.com/codestudio/problems/shortest-supersequence_4244493
string shortestSupersequence(string a, string b)
{
	//lcs code
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	string ans;
	int i = n, j = m;
	while (i > 0 and j > 0) {
		if (a[i - 1] == b[j - 1]) {
			ans = a[i - 1] + ans; //add only one time
			i -= 1;
			j -= 1;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) { //upword
			ans = a[i - 1] + ans;
			i -= 1;
		}
		else {
			ans = b[j - 1] + ans;
			j -= 1;
		}
	}

	//remaining
	while (i > 0) {
		ans = a[i - 1] + ans;
		i -= 1;
	}

	while (j > 0) {
		ans = b[j - 1] + ans;
		j -= 1;
	}

	return ans;

}