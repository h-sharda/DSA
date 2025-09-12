// Problem: 2785. Sort Vowels in a String (Medium)
// Link: https://leetcode.com/problems/sort-vowels-in-a-string

class Solution {
public:
    int vowPos(char &ch) {
        if (ch == 'A') return 0;
        if (ch == 'E') return 1;
        if (ch == 'I') return 2;
        if (ch == 'O') return 3;
        if (ch == 'U') return 4;
        if (ch == 'a') return 5;
        if (ch == 'e') return 6;
        if (ch == 'i') return 7;
        if (ch == 'o') return 8;
        if (ch == 'u') return 9;
        return -1;
    }

    char posVow(int index) {
        if (index == 0) return 'A';
        if (index == 1) return 'E';
        if (index == 2) return 'I';
        if (index == 3) return 'O';
        if (index == 4) return 'U';
        if (index == 5) return 'a';
        if (index == 6) return 'e';
        if (index == 7) return 'i';
        if (index == 8) return 'o';
        if (index == 9) return 'u';
        return '\0';
    }

    string sortVowels(string s) {
        vector<int> freq(10);

        for (char &ch: s) {
            int i = vowPos(ch);
            if(i != -1) freq[i]++;
        }
        
        int j = 0;
        
        for (char &ch: s) {
            while (j < 10 && freq[j] == 0) j++;
            if(vowPos(ch) != -1) {
                ch = posVow(j);
                freq[j]--;
            }
        }

        return s;
    }
};