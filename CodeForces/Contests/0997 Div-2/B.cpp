#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<string> graph(n);
        for (int i =0; i < n; i++) {
            cin >> graph[i];
        }

        vector<int> v(n);
        for (int i = n-1; i >= 0; i--) {
            int count1 = 0;
            
            for (int j = 0; j < i; j++) {
                if (graph[i][j] == '1') count1++;
            }

            for (int j =0; j < n; j++) {
                if (count1 == 0 && v[j] == 0) {
                    v[j] = i + 1;
                    break;
                }
                if (v[j] == 0) count1--;
            }
        }

        for (int i = 0; i < n; i++) cout << v[i] << " ";
        cout << endl;
    }

    return 0;
}