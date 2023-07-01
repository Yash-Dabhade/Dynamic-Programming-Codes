#include <bits/stdc++.h>

// Memoization
// Time Complexity: O(N3), There are total N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.
// Space Complexity: O(N2) + Auxiliary stack space of O(N), N2 for the dp array we are using. 

int func(int i,int j,vector<int>&a,vector<vector<int>> &dp){
	if(i>j) return 0;

	int maxi=INT_MIN;

	if(dp[i][j]!=-1) return dp[i][j];

	for(int ind=i;ind<=j;ind++){
		int cost=a[i-1]*a[ind]*a[j+1]+func(i,ind-1,a,dp)+func(ind+1,j,a,dp);
		maxi=max(cost,maxi);
	}

	return dp[i][j]=maxi;
} 
int maxCoins(vector<int>& a)
{
	int n=a.size();
	a.push_back(1);
	a.insert(a.begin(),1);

	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	return func(1,n,a,dp);
}

// Tabulation
// Time Complexity: O(N3), There are total N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.
// Space Complexity: O(N2), N2 for the dp array we are using.

#include <bits/stdc++.h>

int maxCoins(vector<int>& a)
{
	int n=a.size();
	
	a.push_back(1);
	a.insert(a.begin(),1);

	vector<vector<int>> dp(n+2,vector<int>(n+2,0));

	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(i > j) continue;
			int maxi=INT_MIN;
			for(int ind=i;ind<=j;ind++){
				int cost=a[i-1]*a[ind]*a[j+1]+dp[i][ind-1]+dp[ind+1][j];
				maxi=max(cost,maxi);
			}
			dp[i][j]=maxi;
		}
	}

	return dp[1][n];
}
