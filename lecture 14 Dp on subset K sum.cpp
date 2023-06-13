// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954

#include <bits/stdc++.h>
using namespace std;

//Memoization  Time Complexity: O(N*K), Space Complexity: O(N*K) + O(N)
bool func(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if (target == 0) return true;
    if (ind == 0) return (arr[0] == target);

    if (dp[ind][target] != -1) return dp[ind][target];

    bool notTake = func(ind - 1, target, arr, dp);
    bool take = false;
    if (arr[ind] <= target) take = func(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = (take or notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return func(n - 1, k, arr, dp);
}



//TABULATION  Time Complexity: O(N*K), Space Complexity: O(N*K)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    //Base case
    for (int i = 0; i < n; i++) dp[i][0] = true;

    if (arr[0] <= k) dp[0][arr[0]] = true;

    //nested loops
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



//Space Optimization Time Complexity: O(N*K), Space Complexity: O(K)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k + 1, false), curr(k + 1, false);

    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    if (totalSum < k) return false;
    if (totalSum == k) return true;

    //base cases
    prev[0] = true;
    curr[0] = true;


    //nested loops
    for (int ind = 1; ind < n; ind++) {
        curr[0] = true;
        for (int target = 1; target <= k; target++) {
            bool notTake = prev[target];
            bool take = false;

            if (arr[ind] <= target) take = prev[target - arr[ind]];

            curr[target] = take | notTake;
        }
        prev = curr;
    }
    return curr[k];
}