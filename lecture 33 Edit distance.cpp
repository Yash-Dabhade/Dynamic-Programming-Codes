#include<bits/stdc++.h>

//Memoization :  Time Complexity: O(N*M) Space Complexity: O(N*M) + O(N+M)
int func(int i,int j,string &str1,string &str2,vector<vector<int>> &dp){
    
    if(j<0) return i+1;
    if(i<0) return j+1;

    if(dp[i][j]!=-1) return dp[i][j];

    if(str1[i]==str2[j]){
        return dp[i][j]=func(i-1,j-1,str1,str2,dp);
    }
    else{
        return dp[i][j]= 1+min(func(i-1,j,str1,str2,dp),
            min(func(i,j-1,str1,str2,dp),func(i-1,j-1,str1,str2,dp)));
    }
}

int editDistance(string str1, string str2)
{
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return func(n-1,m-1,str1,str2,dp);
}


//Tabulation Time Complexity: O(N*M)  Space Complexity: O(N*M)
int editDistance(string str1, string str2)
{
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<=n;i++) dp[i][0]=i;
    for(int j=0;j<=m;j++) dp[0][j]=j;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
    }
    return dp[n][m];
}



//Space Optimization Time Complexity: O(N*M)  Space Complexity: O(M)
int editDistance(string str1, string str2)
{
    int n=str1.size();
    int m=str2.size();
    vector<int> prev(m+1,0),curr(m+1,0);

    for(int j=0;j<=m;j++) prev[j]=j;

    for(int i=1;i<=n;i++){
        curr[0]=i;
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
               curr[j]=prev[j-1];
            }
            else{
                curr[j]=1+min(prev[j],min(curr[j-1],prev[j-1]));
            }
        }
        prev=curr;
    }
    return prev[m];
}
