// https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885
#include <bits/stdc++.h>

//Memoization :TC O(N*M*M) * 9 , SC:  O(N) + O(N*M*M)
int func(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>>&dp) {
    //out of bound
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
    if (i == n - 1) {
        if (j1 == j2) return grid[i][j1]; //picking only once if both reached the same cell
        else return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

    //calls for all
    int maxi = -1e9;
    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int value = 0;

            if (j1 == j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];

            int ans = value + func(i + 1, j1 + dj1, j2 + dj2, n, m, grid, dp);
            maxi = max(ans, maxi);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return func(0, 0, m - 1, n, m, grid, dp);
}








//Tabulation Time Complexity: O(N*M*M)*9 , Space Complexity: O(N*M*M)

#include <bits/stdc++.h>
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Write your code here.
    vector < vector < vector < int >>> dp(n, vector < vector < int >> (m,
                                          vector < int > (m, 0)));

    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    //Outer Nested Loops for travering DP Array
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {

                int maxi = INT_MIN;

                //Inner nested loops to try out 9 options
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {

                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        if ((j1 + di < 0 || j1 + di >= m) ||
                                (j2 + dj < 0 || j2 + dj >= m))

                            ans += -1e9;
                        else
                            ans += dp[i + 1][j1 + di][j2 + dj];

                        maxi = max(ans, maxi);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m - 1];

}


//Space Optimization Time Complexity: O(N*M*M)*9, Space Complexity: O(M*M)
int maximumChocolates(int n, int m, vector < vector < int >> & grid) {
    // Write your code here.
    vector < vector < int >> front(m, vector < int > (m, 0)), cur(m, vector < int >
                          (m, 0));

    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    //Outer Nested Loops for travering DP Array
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {

                int maxi = INT_MIN;

                //Inner nested loops to try out 9 options
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {

                        int ans;

                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];

                        if ((j1 + di < 0 || j1 + di >= m) ||
                                (j2 + dj < 0 || j2 + dj >= m))

                            ans += -1e9;
                        else
                            ans += front[j1 + di][j2 + dj];

                        maxi = max(ans, maxi);

                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        front = cur;
    }

    return front[0][m - 1];

}