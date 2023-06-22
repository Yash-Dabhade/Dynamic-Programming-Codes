//https://www.codingninjas.com/codestudio/problems/wildcard-pattern-matching_701650
#include<bits/stdc++.h>

// Time Complexity: O(N*M) for all


//Memoization Space Complexity: O(N*M) + O(N+M)
bool func(int i,int j,string &pattern,string &text,vector<vector<int>> &dp){

   if(i<0 and j<0) return true;

   if(i<0 and j>=0) return false;

   if(i>=0 and j<0){
      for(int ii=0;ii<=i;ii++){
         if(pattern[ii]!='*') return false;
      }
      return true;
   }

   if(dp[i][j]!=-1) return dp[i][j];


   if(pattern[i]==text[j] or pattern[i]=='?'){
      return dp[i][j]=func(i-1,j-1,pattern,text,dp);
   }
   else if(pattern[i]=='*'){
      return dp[i][j]=func(i-1,j,pattern,text,dp) | func(i,j-1,pattern,text,dp);
   }
   else{
      return dp[i][j]=false;
   }
}


bool wildcardMatching(string pattern, string text)
{
   int n=pattern.size();
   int m=text.size();
   vector<vector<int>> dp(n,vector<int>(m,-1));
   return func(n-1,m-1,pattern,text,dp);
}

//Tabulation Space Complexity: O(N*M)
bool wildcardMatching(string pattern, string text)
{
   int n=pattern.size();
   int m=text.size();
   vector<vector<int>> dp(n+1,vector<int>(m+1,0));

   dp[0][0]=true;

   for(int j=1;j<=m;j++){
      dp[0][j]=false;
   }

   for(int i=1;i<=n;i++){
      bool flag=true;
      for(int ii=1;ii<=i;ii++){
        if (pattern[ii - 1] != '*') {
          flag = false;
          break;
        }
      }
       dp[i][0]=flag;
   }

   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
            if(pattern[i-1]==text[j-1] or pattern[i-1]=='?'){
               dp[i][j]=dp[i-1][j-1];
            }
            else if(pattern[i-1]=='*'){
               dp[i][j]=dp[i-1][j] | dp[i][j-1];
            }
            else{
               dp[i][j]=false;
            }
      }  
   }
   return dp[n][m];
}


//Space Optimized Space Complexity: O(M)
#include<bits/stdc++.h>

bool wildcardMatching(string pattern, string text)
{
   int n=pattern.size();
   int m=text.size();
   vector<int> prev(m+1,0),curr(m+1,0);

   prev[0]=true;

   for(int j=1;j<=m;j++){
      prev[j]=false;
   }


   for(int i=1;i<=n;i++){
       bool flag=true;
      for(int ii=1;ii<=i;ii++){
        if (pattern[ii - 1] != '*') {
          flag = false;
          break;
        }
      }
      curr[0]=flag;

      for(int j=1;j<=m;j++){
            if(pattern[i-1]==text[j-1] or pattern[i-1]=='?'){
               curr[j]=prev[j-1];
            }
            else if(pattern[i-1]=='*'){
                 curr[j]=prev[j] | curr[j-1];
            }
            else{
                 curr[j]=false;
            }
      }  
      prev=curr;
   }
   return prev[m];
}
