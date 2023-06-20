// https://www.codingninjas.com/codestudio/problems/longest-palindromic-subsequence_842787
#include <bits/stdc++.h>

// Memoization Time Complexity: O(N*N) Space Complexity: O(N*N)
int lcs(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}


int longestPalindromeSubsequence(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return lcs(s, rev);
}


//Space Optimization Time Complexity: O(N*N) Space Complexity: O(N)
#include <bits/stdc++.h>
int lcs(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                curr[j] = 1 + prev[j - 1];
            }
            else {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }
    return prev[m];
}


int longestPalindromeSubsequence(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return lcs(s, rev);
}