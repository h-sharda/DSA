// Problem: 2948. Make Lexicographically Smallest Array by Swapping Elements (Medium)
// Link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {nums[i], i};
        
        sort(v.begin(), v.end());

        for (int i = 1; i < n; i++) {
            int s = i - 1;
            while (i < n && v[i].first - v[i - 1].first <= limit) i++;
            
            vector<int> t(i-s);
            for (int j = s; j < i; j++) t[j-s] = v[j].second;
            sort(t.begin(), t.end());

            for (int j = s; j < i; j++) nums[t[j-s]] = v[j].first;
        }

        return nums;
    }
};