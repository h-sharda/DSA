// Code 360: Left Rotate an Array by One (Easy)
// link: https://www.naukri.com/code360/problems/left-rotate-an-array-by-one_5026278

#include <bits/stdc++.h> 
using namespace std;

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void rotateArray(vector<int>& arr, int n) {
    int temp = arr[0];
    for (int i =0; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int &i: arr) cin >> i;
        rotateArray(arr, n);
        for (int &i: arr) cout << i << " ";
        cout << endl;
    }
    return 0;
}
