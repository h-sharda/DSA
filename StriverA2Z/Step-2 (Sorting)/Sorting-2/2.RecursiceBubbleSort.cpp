#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void rBubbleSort(vector<int>& v, int n) {
    
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
        
        rBubbleSort(v, n);

        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}