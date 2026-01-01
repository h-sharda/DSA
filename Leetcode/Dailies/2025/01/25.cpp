// Date: 25/01/2025 (Pasandida aurat ka Bday)
// Number: 2948. Make Lexicographically Smallest Array by Swapping Elements (Medium)
// link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> copy(n);

        for (int i =0; i < n; i++) copy[i] = {nums[i], i};

        sort(copy.begin(), copy.end());

        int start = 0;
        for (int i = 1; i < n; i++) {
            if (copy[i].first - copy[i-1].first > limit) {
                vector<int> pos(i - start);
                for(int j = start; j < i; j++) {
                    pos[j-start] = copy[j].second;
                }
                sort(pos.begin(), pos.end());
                for(int j = start; j < i; j++) {
                    nums[pos[j-start]] = copy[j].first;
                }
                start = i;
            }
        }

        vector<int> pos(n - start);
        for(int j = start; j < n; j++) {
            pos[j-start] = copy[j].second;
        }
        sort(pos.begin(), pos.end());
        for(int j = start; j < n; j++) {
            nums[pos[j-start]] = copy[j].first;
        }

        return nums;
    }
};

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, limit;
        cin >> n >> limit;

        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) cin >> v[i];
        
        Solution ob;
        vector<int> ans = ob.lexicographicallySmallestArray(v, limit);
        
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }
    
    return 0;
}
