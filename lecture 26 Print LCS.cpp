#include <bits/stdc++.h>

using namespace std;

void lcs(string s1, string s2) {

  int n = s1.size();
  int m = s2.size();

  vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
  }

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      else
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }

  int len = dp[n][m];
  string ans(len, '$');
  int i = n, j = m, ind = len - 1;

  while (i > 0 and j > 0) {

    if (s1[i - 1] == s2[j - 1]) {
      ans[ind] = s1[i - 1];
      ind -= 1;
      i--;
      j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1]) {
      i -= 1;
    }
    else {
      j -= 1;
    }

  }

  cout << ans << endl;

}

int main() {

  string s1 = "abcde";
  string s2 = "bdgek";

  cout << "The Longest Common Subsequence is ";
  lcs(s1, s2);
}