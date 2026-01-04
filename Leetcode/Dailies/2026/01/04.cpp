// Problem: 1390. Four Divisors (Medium)
// Link: https://leetcode.com/problems/four-divisors

const int lim = 1e5 + 1;
pair<int, int> p[lim];
bool solved = false;

class Solution {
public:
    void solve() {
        solved = true;

        for (int i = 1; i < lim; i++) {
            for (int j = i; j < lim; j+= i) {
                p[j].first++;
                p[j].second += i;
            }
        }
    }

    int sumFourDivisors(vector<int>& nums) {
        if (!solved) solve();

        int ans = 0;
        for (int &num: nums) if (p[num].first == 4) ans += p[num].second;

        return ans;
    }
};