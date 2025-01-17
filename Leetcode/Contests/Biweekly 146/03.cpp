#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int cutH1 = -1, cutH2 = -1, maxH = -1, cutV1 = -1, cutV2 = -1, maxV = -1;
        
        sort (rectangles.begin(), rectangles.end());

        for ( const auto &it: rectangles) {
            maxV = max(maxV, it[2]);
            if (cutV1 == -1) {
                cutV1 = it[2];
            } else if (cutV1 > it[0] && cutV1 < it[2]) {
                if (cutV2 == -1) {
                    cutV1 = it[2];
                } else if (cutV2 > it[0] && cutV2 < it[2]) {
                    cutV1 = it[2];
                    cutV2 = -1;
                } else {
                    cutV1 = cutV2;
                    cutV2 = it[2];
                }
            } else if (cutV2 == -1 && it[2] > cutV1) {
                cutV2 = it[2];
            } else if (cutV2 > it[0] && cutV2 < it[2]) {
                cutV2 = it[2];
            }
        }

        sort (rectangles.begin(), rectangles.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        for ( const auto &it: rectangles) {
            maxH = max(maxH, it[3]);
            if (cutH1 == -1) {
                cutH1 = it[3];
            } else if (cutH1 > it[1] && cutH1 < it[3]) {
                if (cutH2 == -1) {
                    cutH1 = it[3];
                } else if (cutH2 > it[1] && cutH2 < it[3]) {
                    cutH1 = it[3];
                    cutH2 = -1;
                } else {
                    cutH1 = cutH2;
                    cutH2 = it[3];
                }
            } else if (cutH2 == -1 && it[3] > cutH1) {
                cutH2 = it[3];
            } else if (cutH2 > it[1] && cutH2 < it[3]) {
                cutH2 = it[3];
            }
        }       

        return (cutV1 != -1 && cutV2 != -1 && cutV2 != maxV)
            || (cutH1 != -1 && cutH2 != -1 && cutH2 != maxH);
    }
};