// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//dp with memoization

int func(int ind, vector<int> heights, vector<int> &dp) {
	if (ind == 0) return 0;

	if (dp[ind] != -1) return dp[ind];

	ll jumpOne = func(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);

	ll jumpTwo = INT_MAX;
	if (ind > 1) jumpTwo = func(ind - 2, heights, dp)  + abs(heights[ind] - heights[ind - 2]);

	return dp[ind] = min(jumpOne, jumpTwo);
}



int frogJump(int n, vector<int> &heights)
{
	vector<int> dp(n, -1);
	return func(n - 1, heights, dp);
}

//-----------------------------------------------------------------------------


//DP with tabulation


int frogJump(int n, vector<int> &heights)
{
	vector<int> dp(n, 0);
	dp[0] = 0;

	for (int i = 1; i < n; i++) {

		int jumpOne = dp[i - 1] + abs(heights[i] - heights[i - 1]);
		int jumpTwo = INT_MAX;
		if (i > 1) jumpTwo = dp[i - 2] + abs(heights[i] - heights[i - 2]);

		dp[i] = min(jumpOne, jumpTwo);
	}
	return dp[n - 1];
}

//----------------------------------------------------------------------------

//DP with space optimization


int frogJump(int n, vector<int> &heights)
{
	int prev2 = 0, prev = abs(heights[1] - heights[0]);

	for (int i = 2; i < n; i++) {

		int jumpOne = prev + abs(heights[i] - heights[i - 1]);
		int jumpTwo = prev2 + abs(heights[i] - heights[i - 2]);

		int curri = min(jumpOne, jumpTwo);

		prev2 = prev;
		prev = curri;
	}
	return prev;
}




int main() {
	ll n;
	cin >> n;
	vector<ll> heights(n);
	for (ll i = 0; i < n; i++) {
		cin >> heights[i];
	}
	vector<ll> dp(n, -1);
	cout << func(n - 1, heights, dp);
}