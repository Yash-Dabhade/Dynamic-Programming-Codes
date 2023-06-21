#include <bits/stdc++.h> 
int mod=1e9+7;

//Memoization: 
int func(int i,int j,string &t,string &s,vector<vector<int>> &dp){
    if(j<0) return 1;
    if(i<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(t[i]==s[j]){
        return dp[i][j]=(func(i-1,j-1,t,s,dp)+func(i-1,j,t,s,dp))%mod;
    }
    else{
        return dp[i][j]=func(i-1,j,t,s,dp)%mod;
    }
}

int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<vector<int>> dp(lt,vector<int>(ls,-1));
    return func(lt-1,ls-1,t,s,dp);
} 

//Tabulation

int subsequenceCounting(string &t, string &s, int n, int m) {
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(t[i-1]==s[j-1]){
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
            }
            else{
                dp[i][j]=dp[i-1][j]%mod;
            }
        }
    }
    return dp[n][m];
} 

//Space Optimized Ultimate
int mod=1e9+7;


int subsequenceCounting(string &t, string &s, int n, int m) {
   vector<int> prev(m+1,0);

   prev[0]=1;

    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(t[i-1]==s[j-1]){
                prev[j]=(prev[j-1]+prev[j])%mod;
            }
            else{
                prev[j]=prev[j]%mod;
            }
        }
    }
    return prev[m];
} 
