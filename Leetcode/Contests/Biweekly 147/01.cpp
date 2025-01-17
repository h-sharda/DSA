#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {

        int n = p.size(), pos = -1;
        string str1, str2;
        
        for (int i = 0; i < n; i++) {
            if (p[i] != '*') str1.push_back(p[i]);
            else {
                pos = i;
                break;
            }
        }
        for (int i = pos+1; i < n; i++) {
            str2.push_back(p[i]);
        }

        size_t pos1 = s.find(str1), pos2 = s.rfind(str2);
        
        if (pos1 == string::npos || pos2 == string::npos) return false;
        return pos1 + str1.size() <= pos2 ;
    }
};