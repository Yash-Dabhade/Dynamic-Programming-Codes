// https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980
#include<bits/stdc++.h>
using namespace std;

//similar to previous one
bool func(vector<int> &arr, int n, int k) {
	vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

	for (int i = 0; i < n; i++) dp[i][0] = true;

	if (arr[0] <= k) dp[0][arr[0]] = true;

	for (int ind = 1; ind < n; ind++) {
		for (int target = 1; target <= k; target++) {
			bool notTake = dp[ind - 1][target];
			bool take = false;

			if (arr[ind] <= target) take = dp[ind - 1][target - arr[ind]];

			dp[ind][target] = (take or notTake);
		}
	}
	return dp[n - 1][k];
}



bool canPartition(vector<int> &arr, int n)
{
	if (n == 1) return false;

	int totalSum = accumulate(arr.begin(), arr.end(), 0);

	if (totalSum & 1) return false;

	if (func(arr, n, totalSum / 2)) return true;
	return false;

}
