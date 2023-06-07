// https://atcoder.jp/contests/dp/tasks/dp_b
#include<bits/stdc++.h>
using namespace std;


// memoization DP:  Time Complexity: O(N *K) Space Complexity: O(N)
int func(int ind, vector<int> &a, int k, vector<int> &dp) {
	if (ind == 0) {
		return 0;
	}
	if (dp[ind] != -1) return dp[ind];

	int mn = INT_MAX;
	for (int j = 1; j <= k; j++) {
		if (ind - j >= 0) {
			int jump = func(ind - j, a, k, dp) + abs(a[ind] - a[ind - j]);
			mn = min(jump, mn);
		}
	}
	return dp[ind] = mn;
}



int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> dp(n, -1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << func(n - 1, a, k, dp) << endl;

}




//Tabulation DP:  Time Complexity: O(N*K) Space Complexity: O(N)





int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> dp(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0] = 0;
	for (int ind = 1; ind < n; ind++) {
		int mn = INT_MAX;
		for (int j = 1; j <= k; j++) {
			if (ind - j >= 0) {
				int jump = dp[ind - j] + abs(a[ind] - a[ind - j]);
				mn = min(mn, jump);
			}
		}
		dp[ind] = mn;
	}
	cout << dp[n - 1] << endl;

}