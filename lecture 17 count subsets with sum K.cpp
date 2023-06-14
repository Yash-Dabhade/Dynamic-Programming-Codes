// https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532
#include <bits/stdc++.h>

//Memoization TC : O(n*target)  SC: O(n*target) + O(n)
int func(int ind, int target, vector<int> &num, vector<vector<int>> &dp) {
	//pass the sorted num in descending order
	if (target == 0) return 1;
	if (ind == 0) return (num[ind] == target);

	if (dp[ind][target] != -1) return dp[ind][target];

	int notPick = func(ind - 1, target, num, dp);
	int pick = 0;
	if (num[ind] <= target) pick = func(ind - 1, target - num[ind], num, dp);

	return dp[ind][target] = pick + notPick;
}


//tabulation TC : O(n*target)  SC: O(n*target)
int findWays(vector<int> &num, int target)
{
	int n = num.size();
	vector<vector<int>> dp(n, vector<int>(target + 1, 0));
	sort(num.begin(), num.end(), compare);
	for (int i = 0; i < n; i++) dp[i][0] = 1;

	if (num[0] <= target) dp[0][num[0]] = 1;

	for (int ind = 1; ind < n; ind++) {
		for (int tar = 1; tar <= target; tar++) {
			int notPick = dp[ind - 1][tar];

			int pick = 0;
			if (num[ind] <= tar) pick = dp[ind - 1][tar - num[ind]];

			dp[ind][tar] = pick + notPick;
		}
	}

	return dp[n - 1][target];
}

//Space Opimazation TC : O(n*target)  SC: O(target)
int findWays(vector<int> &num, int target)
{
	int n = num.size();
	vector<int> curr(target + 1, 0), prev(target + 1, 0);
	prev[0] = curr[0] = 1;

	sort(num.begin(), num.end(), compare);

	if (num[0] <= target) prev[num[0]] = 1;



	for (int ind = 1; ind < n; ind++) {
		for (int tar = 1; tar <= target; tar++) {
			int notPick = prev[tar];

			int pick = 0;
			if (num[ind] <= tar) pick = prev[tar - num[ind]];

			curr[tar] = pick + notPick;
		}
		prev = curr;
	}

	return prev[target];
}