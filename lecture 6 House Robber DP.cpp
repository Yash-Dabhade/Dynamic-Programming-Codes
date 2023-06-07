// https://www.codingninjas.com/codestudio/problems/house-robber_839733
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//HOUSE ROBBER 2 : Time Complexity: O(N )

ll cal(vector<ll> arr) {
    ll n = arr.size();

    ll prev = arr[0], prev2 = 0;

    for (ll i = 1; i < n; i++) {
        ll pick = arr[i];
        if (i > 1) pick += prev2;

        ll notPick = prev;

        ll curr = max(pick, notPick);

        prev2 = prev;
        prev = curr;
    }
    return prev;
}


long long int houseRobber(vector<int>& valueInHouse)
{
    ll n = valueInHouse.size();

    if (n == 1) return valueInHouse[0];

    vector<ll> first, last;
    for (ll i = 0; i < n; i++) {
        if (i != 0) first.push_back(valueInHouse[i]);
        if (i != n - 1) last.push_back(valueInHouse[i]);
    }

    return max(cal(first), cal(last));

}