// Problem: 1432. Max Difference You Can Get From Changing an Integer (Medium)
// Link: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer

class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        string max = str, min = str;
        int n = str.size();

        int i = 0;
        while (i < n && str[i] == '9' ) i++;
        if ( i != n ) {
            char change = str[i];
            replace(max.begin() + i, max.end(), change, '9');
        }

        if (str[0] != '1') {
            char change = str[0];
            replace(min.begin(), min.end(), change, '1');
        } else {
            i = 0;
            while (i < n && str[i] <= '1' ) i++;
            if ( i != n ) {
                char change = str[i];
                replace(min.begin() + i, min.end(), change, '0');
            }
        }

        return stoi(max) - stoi(min);
    }
};