#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void selectionSort(vector<int>& v, int n) {
    for (int i = 0; i < n; i++) {
        int minPos = i;
        for (int j = i; j < n; j++) {
            if (v[j] < v[minPos]) minPos = j;
        }
        swap(v[i], v[minPos]);
    }
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
        
        selectionSort(v, n);

        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}