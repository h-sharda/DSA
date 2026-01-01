#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool canMake(vector<int> &v, int target, int pos) {
    int n = v.size();

    if (pos >= n-2) return false;

    // for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    // cout << endl << endl;

    if (v[pos + 1] == target-1 && v[pos + 2] == target-1) {
        v[pos] = target;
        v[pos + 1] = target;
        return true;
    } else if (v[pos + 1] != target-1) {
        if (!canMake(v, target-1, pos + 1)) return false;
    } 

    return true;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        sort(v.begin(), v.end(), greater<int>());
        
        bool ans = true;
        
        for (int i = 0; i < n-1; i += 2) {
            if (v[i] == v[i+1]) continue;
            else {
                int diff = v[i + 1] - v[i];
                if (!canMake(v, v[i], i)) {
                    ans = false;
                    break;
                }
            }
        }
        
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
