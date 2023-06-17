#include <bits/stdc++.h>
int compare(int a, int b) {
    if (a > b) return 1;
    else return 0;
}

// Time Complexity: O(N*K) ,Space Complexity: O(N*K)
int func(int n, int target, vector<int> arr) {
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    if (arr[0] <= target) dp[0][arr[0]] = 1;

    for (int ind = 1; ind < n; ind++) {
        for (int tar = 1; tar <= target; tar++) {

            int notTake = 0 + dp[ind - 1][tar];

            int take = 0;
            if (arr[ind] <= tar) take = dp[ind - 1][tar - arr[ind]];

            dp[ind][tar] = take + notTake;
        }
    }
    return dp[n - 1][target];
}


int countPartitions(int n, int target, vector<int> &arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    int newTarget = (totalSum - target);
    if (newTarget & 1 or newTarget < 0) return 0;
    return func(n, newTarget / 2, arr);
}

int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    return countPartitions(n, target, arr);
}
