//https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349
#include <bits/stdc++.h>

//Memoization : Time Complexity: O(N*M)
int func(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if (i == 0 && j == 0) return grid[i][j];
    if (i < 0 || j < 0) return 1e9;

    if (dp[i][j] != -1) return dp[i][j];

    int up = grid[i][j] + func(i - 1, j, grid, dp);
    int left = grid[i][j] + func(i, j - 1, grid, dp);

    return dp[i][j] = min(up, left);
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    if (n == 0) n = 1;
    if (m == 0) m = 1;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return func(n - 1, m - 1, grid, dp);
}


//Tabulation:  Time Complexity: O(N*M), Space Complexity: O(N*M)
#include <bits/stdc++.h>
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    if (n == 0) n = 1;
    if (m == 0) m = 1;

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 and j == 0) {
                dp[i][j] = grid[i][j];
                continue;
            }
            int up = grid[i][j], left = grid[i][j];

            if (i > 0) up += dp[i - 1][j];
            else up += 1e9;

            if (j > 0) left += dp[i][j - 1];
            else left += 1e9;

            dp[i][j] = min(up, left);
        }
    }
    return dp[n - 1][m - 1];
}

//Space Optimization: Time Complexity: O(M*N), Space Complexity: O(N)
#include <bits/stdc++.h>
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    if (n == 0) n = 1;
    if (m == 0) m = 1;

    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++) {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++) {
            if (i == 0 and j == 0) {
                curr[j] = grid[i][j];
                continue;
            }
            int up = grid[i][j], left = grid[i][j];

            if (i > 0) up += prev[j];
            else up += 1e9;

            if (j > 0) left += curr[j - 1];
            else left += 1e9;

            curr[j] = min(up, left);
        }
        prev = curr;
    }
    return prev[m - 1];
}