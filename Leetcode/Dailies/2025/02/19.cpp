// Problem: 1415. The k-th Lexicographical String of All Happy Strings of Length n (Medium)
// Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n

class Solution {
public:
    string getHappyString(int n, int k) {
        k--;
        int i = 1 << (n-1);
        
        if (k >= 3 * i) return "";

        string ans;

        while (ans.size() < n) {
            int num = k / i;
            k %= i;
            i /= 2;

            if (ans.empty()) ans.push_back('a' + num);
            else {
                if (num == 0) {
                    if (ans.back() == 'a') ans.push_back('b');
                    else ans.push_back('a');
                } if (num == 1) {
                    if (ans.back() == 'c') ans.push_back('b');
                    else ans.push_back('c');
                }
            }
        }

        return ans;
    }
};