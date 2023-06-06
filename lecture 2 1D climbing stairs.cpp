// https://leetcode.com/problems/climbing-stairs/description/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


class Solution {
public:
	int climbStairs(int n) {
		vector<ll> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (ll i = 2; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};