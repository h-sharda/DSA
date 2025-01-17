// Leetcode: 875. Koko Eating Bananas (Medium)
// link: https://leetcode.com/problems/koko-eating-bananas/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    bool isValid (vector<int> &piles, int h, int speed) {
        int n = piles.size();
        
        for (int i = 0; i < n && h >= 0; i++) {
            h -= (piles[i] + speed - 1)/speed;
        }

        return h >= 0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while ( low <= high ) {
            int mid = low + (high-low)/2;
            if (isValid(piles, h, mid)) high = mid-1;
            else low = mid +1;
        }

        return low;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, h;
        cin >> n >> h;
        vector<int> piles(n);
        for (int i = 0; i < n; i++) cin >> piles[i];
        Solution obj;
        cout << obj.minEatingSpeed(piles, h) << endl;
    }
    return 0;
}