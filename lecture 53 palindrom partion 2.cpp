#include <bits/stdc++.h> 
bool isPalindrome(string &s){
    string r=s;
    reverse(r.begin(),r.end());
    return s==r;
}

//Memoization  Time Complexity: O(N2)
int func(int i,int n,string &str,vector<int> &dp){
    if(i==n) return 0;

    if(dp[i]!=-1) return dp[i];

    int minCost=INT_MAX;
    string temp;
    for(int j=i;j<n;j++){
        temp+=str[j];
        if(isPalindrome(temp)){
            int cost=1+func(j+1,n,str,dp);
            minCost=min(cost,minCost);
        }
    }
    return dp[i]=minCost;
}

int palindromePartitioning(string str) {
   int n=str.size();
   vector<int> dp(n,-1);
   return func(0,n,str,dp)-1;
}



// Tabulation Time Complexity: O(N2)
int palindromePartitioning(string str) {
   int n=str.size();
   vector<int> dp(n+1,0);

   for(int i=n-1;i>=0;i--){
        int minCost=INT_MAX;
        string temp;
        for(int j=i;j<n;j++){
            temp+=str[j];
            if(isPalindrome(temp)){
                int cost=1+dp[j+1];
                minCost=min(cost,minCost);
            }
        }
        dp[i]=minCost;
   } 


   return dp[0]-1;
}





