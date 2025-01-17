// Code360: Ceil The Floor
// link: https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int ceil = -1, floor =-1;
	
	int low = 0, high = a.size()-1;

	while ( low <= high){
		int mid = low + (high-low)/2;
		if ( a[mid] == x) return {x,x};
		else if ( a[mid] < x ) low = mid +1;
		else high = mid-1;
	}
	
	if (low != a.size()) ceil = a[high+1];
	if (high != -1) floor = a[low -1];

	return {floor, ceil};

}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        vector<int> arr;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        int k;
        cin >> k;
        pair<int, int> ans = getFloorAndCeil(arr, n, k);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}
