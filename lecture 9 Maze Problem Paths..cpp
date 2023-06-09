//https://www.codingninjas.com/codestudio/problems/maze-obstacles_977241

// Memoization : TC O(N*M)   SC O((N-1)+(M-1))+O(N*M)
int func(int i, int j, vector<vector<int>> &mat, vector<vector<int>>&dp) {
    if (i >= 0 && j >= 0 && mat[i][j] == -1)
        return 0;
    if (i == 0 && j == 0) {
        return 1;
    }
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int up = func(i - 1, j, mat, dp);
    int left = func(i, j - 1, mat, dp);

    return dp[i][j] = (up + left) % mod;

}


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return func(n - 1, m - 1, mat, dp);
}




// Tabulation :  TC O(N*M)   SC O(N*M)

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }

            int up = 0, left = 0;

            if (i > 0) up = dp[i - 1][j];
            if (j > 0) left = dp[i][j - 1];

            dp[i][j] = (up + left) % mod;
        }
    }
    return dp[n - 1][m - 1];

}


// space optimization Time Complexity: O(M*N) , Space Complexity: O(N)

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++) {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == -1) {
                curr[j] = 0;
                continue;
            }
            if (i == 0 && j == 0) {
                curr[j] = 1;
                continue;
            }

            int up = 0, left = 0;

            if (i > 0) up = prev[j];
            if (j > 0) left = curr[j - 1];

            curr[j] = (up + left) % mod;
        }
        prev = curr;
    }
    return prev[m - 1];

}