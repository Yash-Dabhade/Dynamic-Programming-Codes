// https://www.codingninjas.com/studio/problems/cost-to-cut-a-chocolate_3208460
#include <bits/stdc++.h> 

//Memoization Time Complexity: O(N*N*N)  Space Complexity: O(N*N) + O(N)     
int func(int i,int j,vector<int> &cuts,vector<vector<int>> &dp){
    if(i>j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int mini=INT_MAX;
    for(int ind=i;ind<=j;ind++){
        int ans=cuts[j+1]-cuts[i-1]+func(i,ind-1,cuts,dp)+func(ind+1,j,cuts,dp);
        mini=min(ans,mini);
    }

    return dp[i][j]=mini;
}


int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
    return func(1,c,cuts,dp);
}



// Tabulation Time Complexity: O(N*N*N)  Space Complexity: O(N*N) 

#include <bits/stdc++.h> 

int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    
    vector<vector<int>> dp(c+2,vector<int>(c+2,0));

    for(int i=c;i>=1;i--){
        for(int j=1;j<=c;j++){
            if(i>j) continue;
            
            int mini=INT_MAX;
            for(int ind=i;ind<=j;ind++){
                int ans=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                mini=min(ans,mini);
            }

            dp[i][j]=mini;
        }
    }
    return dp[1][c];

    return func(1,c,cuts,dp);
}


