// Problem: 2342. Max Sum of a Pair With Equal Sum of Digits (Medium)
// Link: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits

class Solution {
public:
    int sumDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int ans = -1;
        vector<pair<int, int>> v(82);

        for (int num : nums) {
            int val = sumDigits(num);

            auto &[first, second] = v[val];
            if (num > first) {
                second = first;
                first = num;
            } else if (num > second) {
                second = num;
            }

            if (second != 0) {
                ans = max(ans, first + second);
            }
        }

        return ans;
    }
};
