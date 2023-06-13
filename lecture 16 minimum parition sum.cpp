// https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494

#include <bits/stdc++.h>

//Time Complexity: O(N*k) +O(N) +O(N)  Space Complexity: O(k)
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = accumulate(arr.begin(), arr.end(), 0);
	int k = totalSum;

	vector<bool> curr(k + 1, false), prev(k + 1, false);

	curr[0] = true;
	prev[0] = true;

	if (arr[0] <= k) prev[arr[0]] = true;

	for (int ind = 1; ind < n; ind++) {
		for (int target = 1; target <= k; target++) {
			bool notTake = prev[target];

			bool take = false;
			if (arr[ind] <= target) take = prev[target - arr[ind]];

			curr[target] = take | notTake;
		}
		prev = curr;
	}

	int mini = 1e9;
	for (int s1 = 0; s1 <= totalSum / 2; s1++) {
		if (prev[s1]) {
			int s2 = totalSum - s1;
			mini = min(abs(s2 - s1), mini);
		}
	}
	return mini;

}
