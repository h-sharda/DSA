// Problem: 2566. Maximum Difference by Remapping a Digit (Easy)
// Link: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit

class Solution {
    public int minMaxDifference(int num) {
        String str = Integer.toString(num);
        int n = str.length();
        int i = 0;

        StringBuilder maxStr = new StringBuilder(str);
        while (i < n && str.charAt(i) == '9') i++;
        if (i != n) {
            char change = str.charAt(i);
            while (i < n) {
                if (maxStr.charAt(i) == change) {
                    maxStr.setCharAt(i, '9');
                }
                i++;
            }
        }
        int max = Integer.parseInt(maxStr.toString());

        i = 0;
        StringBuilder minStr = new StringBuilder(str);
        char change = str.charAt(0);
        while (i < n) {
            if (minStr.charAt(i) == change) {
                minStr.setCharAt(i, '0');
            }
            i++;
        }
        int min = Integer.parseInt(minStr.toString());

        return max -min;        
    }
}