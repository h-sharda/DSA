#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int partition(vector<int>& v, int start, int end) {
    int pivot = v[start];
    int i = start + 1, j = end;
    
    while ( i <= j ) {
        if (v[i] < pivot ) i++;
        else if (v[j] > pivot) j--;
        else swap(v[i++], v[j--]);
    }

    swap(v[start], v[j]);
    return j;
}

void sort(vector<int>& v, int start, int end) {
    if (start >= end) return;
    int pos = partition(v, start, end);
    sort(v, start, pos-1);
    sort(v, pos+1, end);
}

void quickSort(vector<int>& v, int n) {
    sort(v, 0, n-1);
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
        
        quickSort(v, n);

        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}