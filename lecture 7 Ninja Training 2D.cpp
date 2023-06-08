//https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003
#include<bits/stdc++.h>
using namespace std;


// Memoization : TC : O(N*4*3) SC: O(N)+O(N*4)
int func(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if (day == 0) {
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) maxi = max(points[0][task], maxi);
        }
        return maxi;
    }

    if (dp[day][last] != -1) return dp[day][last];

    int maxi = 0;
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int total = points[day][task] + func(day - 1, task, points, dp);
            maxi = max(total, maxi);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{   vector<vector<int>> dp(n, vector<int>(4, -1));
    return func(n - 1, 3, points, dp);
}





//Tabulation : Time Complexity: O(N*4*3), Space Complexity: O(N*4)
int ninjaTraining(int n, vector<vector<int>> &points)
{   vector<vector<int>> dp(n, vector<int>(4, 0));

    //base case
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    dp[day][last] = max(points[day][task] + dp[day - 1][task], dp[day][last]);
                }
            }
        }
    }
    return dp[n - 1][3];
}

//space optimization Time Complexity: O(N*4*3), Space Complexity: O(4)
int ninjaTraining(int n, vector<vector<int>> &points)
{   vector<int> dp(4, 0);

    //base case
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][1], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++) {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++) {
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    temp[last] = max(points[day][task] + dp[task], temp[last]);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}
