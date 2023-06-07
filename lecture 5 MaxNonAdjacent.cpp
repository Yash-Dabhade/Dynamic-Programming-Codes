#include <bits/stdc++.h>
using namespace std;

// Memoization : TC O(N)   SC O(N)+O(N)
int func(int ind, vector<int> &nums, vector<int> &dp) {
    if (ind == 0) return nums[ind];
    if (ind < 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    int pick = nums[ind] + func(ind - 2, nums, dp);
    int notPick = 0 + func(ind - 1, nums, dp);

    return dp[ind] = max(pick, notPick);
}


int maximumNonAdjacentSum(vector<int> &nums) {
    // Write your code here
    int n = nums.size();
    vector<int> dp(n, -1);
    return func(n - 1, nums, dp);
}



//Tabulation : TC O(N)  SC O(N)

int maximumNonAdjacentSUM(vector<int> &nums) {

    int n = nums.size();
    vector<int> dp(n, -1);

    dp[0] = nums[0];

    for (int ind = 1; ind < n; ind++) {

        int pick = nums[ind];

        if (ind > 1) pick += dp[ind - 2];

        int notpick = dp[ind - 1];

        dp[ind] = max(pick, notpick);
    }

    return dp[n - 1];
}



//Space Optimization : TC O(N)  SC O(1)

int maximumNonAdjacentSumOptimized(vector<int> &nums) {

    int n = nums.size();

    int prev = nums[0], prev2 = 0;

    for (int ind = 1; ind < n; ind++) {

        int pick = nums[ind];
        if (ind > 1) pick += prev2;

        int notpick = prev;

        int curr = max(pick, notpick);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}