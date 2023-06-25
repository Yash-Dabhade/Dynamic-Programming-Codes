// https://www.codingninjas.com/codestudio/problems/longest-increasing-subsequence_630459
#include<bits/stdc++.h>

//Memoization : Gives run time error for constraints
int func(int ind,int prev_ind,int arr[],int n,vector<vector<int>> &dp){
    if(ind==n) return 0;

    if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];

    int notTake=0+func(ind+1,prev_ind,arr,n,dp);
    int take=0;
    if(ind==-1 or arr[ind]>arr[prev_ind]){
        take=1+func(ind+1,ind,arr,n,dp);
    }
    return dp[ind][prev_ind+1]=max(take,notTake);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return func(0,-1,arr,n,dp);
}
