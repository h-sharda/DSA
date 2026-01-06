// Problem: 2698. Find the Punishment Number of an Integer (Medium)
// Link: https://leetcode.com/problems/find-the-punishment-number-of-an-integer

vector<int> nums;
bool solved = false;

class Solution {
public:
    bool isValid (int sq, int total, int target) {
        if (sq == 0) return total == target;
        if (total > target) return false;
        
        int sum = 0, pow = 1;
        while (sq > 0) {
            sum += (sq % 10) * pow;
            sq /= 10;
            pow *= 10;
            if (isValid(sq, total + sum, target)) return true;
        }

        return false;
    }

    void solve() {
        solved = true;
        nums.resize(1001);
        int sum = 0;
        for (int i = 1; i <= 1000; i++) {
            if (isValid(i*i, 0, i)) sum += i*i;
            nums[i] = sum;            
        }
    }

    int punishmentNumber(int n) {
        if(!solved) solve();
        return nums[n];
    }
};