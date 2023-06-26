#include <bits/stdc++.h> 
// Time Complexity: O(N*N * l)   Space Complexity: O(N)
bool compare(string &s1,string &s2){
    if(s1.size()!=s2.size()+1) return false;
    
    int first=0,second=0;
   
    while(first<s1.size()){
        if(second<s2.size() and s1[first]==s2[second]){
            first++;
            second++;
        }
        else{
            first++;
        }
    }
    if(first==s1.size() and second==s2.size()) return true;
    return false;
}

bool cmp(string &s1,string &s2){
    return s1.size()<s2.size();
}
int longestStrChain(vector<string> &arr)
{
    int n=arr.size();
    sort(arr.begin(),arr.end(),cmp);

    vector<int> dp(n,1);
    int maxi=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(compare(arr[i],arr[j]) and dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
        maxi=max(dp[i],maxi);
    }

    return maxi;
}
