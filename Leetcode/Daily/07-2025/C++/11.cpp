// Problem: 2402. Meeting Rooms III (Hard)
// Link: https://leetcode.com/problems/meeting-rooms-iii

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<int> v(n);
        priority_queue<int, vector<int>, greater<>> pq1; // unoccupied rooms
        for (int i =0; i < n; i++) pq1.push(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq2; // occupied rooms, <End Duration, Room>

        for (auto &it: meetings) {
            while (!pq2.empty() && pq2.top().first <= it[0]) {
                pq1.push(pq2.top().second);
                pq2.pop();
            }

            if (pq1.empty()) {
                long long currMin = pq2.top().first;
                pq1.push(pq2.top().second);
                pq2.pop();

                pq2.emplace(currMin + it[1]-it[0] , pq1.top());
                v[pq1.top()]++;
                pq1.pop();

            } else {
                pq2.emplace(it[1], pq1.top());
                v[pq1.top()]++;
                pq1.pop();
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) if (v[i] > v[ans]) ans = i;

        return ans;
    }
};