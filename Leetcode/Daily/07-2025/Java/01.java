// Problem: 3330. Find the Original Typed String I (Easy)
// Link: https://leetcode.com/problems/find-the-original-typed-string-i

class Solution {
    public int possibleStringCount(String word) {
        int ans = 1;
        int n = word.length();

        for (int i = 1; i < n; i++) {
            if (word.charAt(i) == word.charAt(i-1)) ans++;
        }

        return ans;
    }
}