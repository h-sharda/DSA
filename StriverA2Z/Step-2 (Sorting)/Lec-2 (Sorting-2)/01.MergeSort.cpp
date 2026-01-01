#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void merge(vector<int> &v, int start, int mid, int end) {
    vector<int> temp(end-start+1);
    int i = start, j = mid+1, k = 0;

    while (i <= mid || j <= end) {
        if ( i == mid + 1) temp[k++] = v[j++];
        else if ( j == end +1) temp[k++] = v[i++];
        else if ( v[i] <= v[j] ) temp[k++] = v[i++];
        else temp[k++] = v[j++];
    }
    
    for (int i =start; i <= end; i++) v[i] = temp[i-start];
}

void sort(vector<int>& v, int start, int end) {
    if (start >= end) return;
    int mid = start + (end-start)/2;
    sort(v, mid+1, end);
    sort(v, start, mid);
    merge(v, start, mid, end);
}

void mergeSort(vector<int>& v, int n) {
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
        
        mergeSort(v, n);

        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}