// Problem: 3005. Count Elements With Maximum Frequency (Easy)
// Link: https://leetcode.com/problems/count-elements-with-maximum-frequency

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> freq;
        int maxx = 0;

        for (int num : nums) {
            int c = ++freq[num];
            if ( c > maxx ) {
                maxx = c;
                ans = c;
            } else if (c == maxx) ans += c;
        }

        return ans;
    }
};