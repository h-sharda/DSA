// Code360: Allocate Books
// link: https://www.naukri.com/code360/problems/allocate-books_1090540

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isValid(vector<int> &arr, int students, int maxPages) {
    int n = arr.size(), read = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] + read > maxPages) {
            students--;
            read = arr[i];
        } else read += arr[i];
        if (students == 0) return false;
    }

    return true;
}

int findPages(vector<int>& arr, int n, int m) {

    if (m > n) return -1;
    
    int low = 0, high = 0, ans = -1;
    for (int &i: arr) {
        low = max(low, i);
        high += i;
    }

    while ( low <= high) {
        int mid = low + (high - low)/2;
        if (isValid(arr, m, mid)) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }

    return ans; 
}


int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector <int> v(n);
        for ( int i =0; i < n ; i++) {
            cin >> v[i];
        }

        cout << findPages(v, n, m) << endl;
    }
    return 0;
}