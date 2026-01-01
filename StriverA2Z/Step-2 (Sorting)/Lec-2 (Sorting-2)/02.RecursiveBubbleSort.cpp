#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void recurse(vector<int> &v, int n, int j, bool swapped) {

    if (j == n-1) {
        if (!swapped) return;
        j = 0, n--;
    }
    if ( n == 1 ) return;

    if (v[j+1] < v[j]) {
        swapped = true;
        swap (v[j+1], v[j]);
    }
    
    recurse(v, n, j+1, swapped);
}

void rBubbleSort(vector<int>& v, int n) {
    recurse (v, n, 0, false);
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