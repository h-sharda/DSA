// Problem: 66. Plus One (Easy)
// Link: https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i=digits.size()-1; i>=0; i--){
            if ( digits[i] + carry == 10 ){
                carry = 1;
                digits[i] = 0;
            } else {
                digits[i]+= carry;
                carry = 0;
            }
        }
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};