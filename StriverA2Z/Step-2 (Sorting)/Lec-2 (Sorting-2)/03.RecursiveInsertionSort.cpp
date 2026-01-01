#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void sort(vector<int> &v, int n, int i, int j, int key) {

    if (j >= 0 && v[j] > key){
        v[j+1] = v[j];
        j--;
    } else {
        v[j+1] = key;
        i++;
        if ( i == n ) return;
        key = v[i], j = i-1;
    }

    sort(v, n, i, j, key);
}

void rInsertionSort(vector<int>& v, int n) {
    if ( n <= 1 ) return;
    sort (v, n, 1, 0, v[1]);
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
        
        rInsertionSort(v, n);

        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}