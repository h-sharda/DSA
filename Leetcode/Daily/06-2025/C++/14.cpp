// Problem: 2566. Maximum Difference by Remapping a Digit (Easy)
// Link: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit

class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        int n = str.size();
        int i = 0;

        while (i < n && str[i] == '9') i++;
        if (i != n) {
            char change = str[i];
            while (i < n) {
                if (str[i] == change) str[i] = '9';
                i++;
            }
        }

        int max = stoi(str);

        str = to_string(num);
        i = 0;

        char change = str[i];
        while (i < n) {
            if (str[i] == change) str[i] = '0';
            i++;
        }

        int min = stoi(str);

        return max-min;
    }
};