// https://www.codingninjas.com/codestudio/problems/can-you-make_4244510
#include <bits/stdc++.h>

//Tabulation  TC: O(n*m)   SC: O(n*m);
int lcs(string &s, string &t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        }
    }

    return dp[n][m];

}

int canYouMake(string &str, string &ptr)
{
    int n = str.size(), m = ptr.size();
    int longestSubsequence = lcs(str, ptr);
    int deletions = abs(n - longestSubsequence);
    int insertions = abs(m - longestSubsequence);
    return insertions + deletions;

}



//Space Optimizaiton TC: O(n*m)   SC: O(m);

#include <bits/stdc++.h>
int lcs(string &s, string &t) {
    int n = s.size(), m = t.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
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

int canYouMake(string &str, string &ptr)
{
    int n = str.size(), m = ptr.size();
    int longestSubsequence = lcs(str, ptr);
    int deletions = abs(n - longestSubsequence);
    int insertions = abs(m - longestSubsequence);
    return insertions + deletions;

}