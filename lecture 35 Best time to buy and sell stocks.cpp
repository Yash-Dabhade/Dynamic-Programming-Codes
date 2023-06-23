// https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405
#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices) {
    // Write your code here.
    int mini = prices[0], profit = 0;
    for (int i = 1; i < prices.size(); i++) {
        profit = max(profit, prices[i] - mini);
        mini = min(prices[i], mini);
    }
    return profit;
}