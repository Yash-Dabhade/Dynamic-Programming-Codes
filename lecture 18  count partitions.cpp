#include <bits/stdc++.h> 

int mod=1e9+7;

bool compare(int x, int y) {
	if (x > y) return true;
	return false;
}

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

			dp[ind][tar] = (pick + notPick)%mod;
		}
	}

	return dp[n - 1][target];
}


int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totalSum=accumulate(arr.begin(),arr.end(),0);
    int newTarget=(totalSum-d);

    if(newTarget&1 or newTarget<0) return 0;
    else return findWays(arr,newTarget/2);
}


