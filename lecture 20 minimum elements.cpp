// https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091

#include <bits/stdc++.h>

//Memoization : Time Complexity: O(N*target) Space Complexity: O(N*target) + O(N)
int func(int ind, int tar, vector<int> &num, vector<vector<int>> &dp) {
    if (ind == 0) {
        if (tar % num[ind] == 0) return tar / num[ind];
        return 1e9;
    }

    if (dp[ind][tar] != -1) return dp[ind][tar];

    int notTake = 0 + func(ind - 1, tar, num, dp);

    int take = 1e9;
    if (num[ind] <= tar) take = 1 + func(ind, tar - num[ind], num, dp);

    return dp[ind][tar] = min(notTake, take);
}
int minimumElements(vector<int> &num, int target)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    int ans = func(n - 1, target, num, dp);

    if (ans >= 1e9) return -1;
    return ans;
}



//Tabulation:  Time Complexity: O(N*target) Space Complexity: O(N*target)
int minimumElements(vector<int> &num, int target)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int tar = 0; tar <= target; tar++) {
        if (tar % num[0] == 0) dp[0][tar] = tar / num[0];
        else dp[0][tar] = INT_MAX;
    }

    for (int ind = 1; ind < n; ind++) {
        for (int tar = 0; tar <= target; tar++) {

            int notTake = 0 + dp[ind - 1][tar];

            int take = 1e9;
            if (num[ind] <= tar) take = 1 + dp[ind][tar - num[ind]];

            dp[ind][tar] = min(notTake, take);
        }
    }


    int ans = dp[n - 1][target];

    if (ans >= 1e9) return -1;
    return ans;
}


//Space Optimization:  Time Complexity: O(N*target) Space Complexity: O(target)

#include <bits/stdc++.h>
int minimumElements(vector<int> &num, int target)
{
    int n = num.size();
    vector<int> prev(target + 1, 0), curr(target + 1, 0);

    for (int tar = 0; tar <= target; tar++) {
        if (tar % num[0] == 0) prev[tar] = tar / num[0];
        else prev[tar] = INT_MAX;
    }

    for (int ind = 1; ind < n; ind++) {
        for (int tar = 0; tar <= target; tar++) {

            int notTake = 0 + prev[tar];

            int take = 1e9;
            if (num[ind] <= tar) take = 1 + curr[tar - num[ind]];

            curr[tar] = min(notTake, take);
        }
        prev = curr;
    }


    int ans = prev[target];

    if (ans >= 1e9) return -1;
    return ans;
}