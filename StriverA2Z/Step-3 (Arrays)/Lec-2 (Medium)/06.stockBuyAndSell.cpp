// Leetcode: 121. Best Time to Buy and Sell Stock (Easy)
// link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn = INT_MAX, ans = 0;
        for (int &i: prices) {
            if ( i < minn ) minn = i;
            else ans = max(ans, i-minn);
        }
        return ans;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> prices(n);
        for (int i = 0; i < n; i++) cin >> prices[i];

        Solution ob;
        cout << ob.maxProfit(prices) << "\n";      
    }
    return 0;
}