#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int ans = 0, n = startTime.size();

        int start = 0, end = 0, blocks = 0, i = 0, j = 0, len = 0;

        while (j < n && blocks < k) {
            len += endTime[j] - startTime[j];
            blocks++;
            j++;
        }

        if (j == n) return eventTime - len;
        
        end = startTime[j];        
        ans = max(ans, end-start - len);

        // cout << j;
        
        while ( j < n) {

            // cout << start << " " << end << " " << len << endl;
            start = endTime[i];
            len -= endTime[i] - startTime[i];
            i++;

            len += endTime[j] - startTime[j];
            j++;
            if (j == n) break;
            
            end = startTime[j];
            
            ans = max(ans, end-start - len);
        }

        ans = max(ans, eventTime-start - len);

        return ans;
    }
};