#include <bits/stdc++.h>
using namespace std;
//AUTHOR : yashdabhade283

typedef long long int ll;



// dp memoization TC:O(n) SC:O(n)+O(n)
ll fib(ll n, vector<ll> &dp) {
	if (n <= 1) return n;
	if (dp[n] != -1) return dp[n];
	return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

void solve() {
	ll n;
	cin >> n;
	vector<ll> dp(n + 1, -1);
	cout << fib(n, dp) << endl;
}

//-----------------------------------------------------------------------------


// dp tabulation TC:O(n) SC:O(n)
void solve() {
	ll n;
	cin >> n;
	vector<ll> dp(n + 1, 0);

	dp[0] = 0;
	dp[1] = 1;

	for (ll i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << endl;
}


//-----------------------------------------------------------------------------

//dp spaceoptization TC:O(n) SC:O(1)

void solve() {
	ll n;
	cin >> n;
	ll prev2 = 0, prev = 1;
	for (ll i = 2; i <= n; i++) {
		ll curri = prev + prev2;
		prev2 = prev;
		prev = curri;
	}
	cout << prev << endl;
}




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
