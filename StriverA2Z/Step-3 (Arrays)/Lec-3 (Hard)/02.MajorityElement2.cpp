// Leetcode: 229. Majority Element II
// link: https://leetcode.com/problems/majority-element-ii/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 = INT_MIN, num2 = INT_MIN, count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++) {
            if (count1 == 0 && nums[i] != num2) num1 = nums[i], count1 = 1;
            else if (nums[i] == num1) count1++;
            else if (count2 == 0) num2 = nums[i], count2 = 1;
            else if (nums[i] == num2) count2++;
            else count1--, count2--;
        }

        vector<int> ans;
        count1 =0, count2 =0;
        for (int i =0; i < n; i++) {
            if (nums[i] == num1) count1++;
            else if (nums[i] == num2) count2++;
        }
        
        if (count1 > n/3 ) ans.push_back(num1);
        if (count2 > n/3 ) ans.push_back(num2);

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
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        Solution s;
        vector<int> result = s.majorityElement(nums);
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}