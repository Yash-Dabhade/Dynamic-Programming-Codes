// https://www.codingninjas.com/codestudio/problems/divisible-set_3754960
#include <bits/stdc++.h> 
//Time Complexity: O(N*N)  Space Complexity: O(N)
vector<int> divisibleSet(vector<int> &arr){
    int n=arr.size();
    vector<int> dp(n,1),hash(n);
    int maxi=1;
    int lastIndex=0;
    sort(arr.begin(),arr.end()); 

    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(arr[i]%arr[prev]==0 and 1+dp[prev]>dp[i]){
                dp[i]=1+dp[prev];
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lastIndex=i;
        }
    }


    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex]!=lastIndex){
        lastIndex=hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    
    reverse(temp.begin(),temp.end());
    return temp;


}
