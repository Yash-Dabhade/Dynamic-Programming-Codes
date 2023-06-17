#include<bits/stdc++.h>

//Memoization Time Complexity: O(N*T) Space Complexity: O(N*T) + O(N)
long func(int ind, int value, int *a, vector<vector<long>> &dp) {

    if (ind == 0) {
        return (value % a[0] == 0);
    }

    if (dp[ind][value] != -1) return dp[ind][value];

    long notTake = func(ind - 1, value, a, dp);
    long take = 0;
    if (a[ind] <= value) take = func(ind, value - a[ind], a, dp);

    return dp[ind][value] = take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>>  dp(n, vector<long>(value + 1, -1));
    return func(n - 1, value, denominations, dp);
}



//tabulation Time Complexity: O(N*T)  Space Complexity: O(N*T)
#include<bits/stdc++.h>
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>>  dp(n, vector<long>(value + 1, 0));

    for (int tar = 0; tar <= value; tar++) {
        dp[0][tar] = (tar % denominations[0] == 0);
    }

    for (int ind = 1; ind < n; ind++) {
        for (int tar = 0; tar <= value; tar++) {
            long notTake = dp[ind - 1][tar];
            long take = 0;
            if (denominations[ind] <= tar) take = dp[ind][tar - denominations[ind]];

            dp[ind][tar] = take + notTake;
        }
    }

    return dp[n - 1][value];

}

//Space optimization Time Complexity: O(N*T) Space Complexity: O(T)
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<long> prev(value + 1, 0), curr(value + 1, 0);

    for (int tar = 0; tar <= value; tar++) {
        prev[tar] = (tar % denominations[0] == 0);
    }

    for (int ind = 1; ind < n; ind++) {
        for (int tar = 0; tar <= value; tar++) {
            long notTake = prev[tar];
            long take = 0;
            if (denominations[ind] <= tar) take = curr[tar - denominations[ind]];

            curr[tar] = take + notTake;
        }
        prev = curr;
    }

    return prev[value];

}