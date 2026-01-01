#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isOddSquare (int num) {
    int i = 1;
    while ( i*i < num ){
        i += 2;
    }
    return i*i == num;
}

int happyDays(vector<int> &nums) {
    int n = nums.size();
    int placed = 0, ans = 0;
    for (int i : nums){
        placed += i;
        if ( isOddSquare(placed) ) ans++;
    }
    return ans;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector <int> v(n,0);
        for ( int i =0; i < n ; i++) {
            int temp;
            cin >> temp;
            v[i] = temp;
        }

        int ans = happyDays(v);
        cout << ans << endl;
    }

    return 0;
}