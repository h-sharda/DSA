#include <bits/stdc++.h>
using namespace std;
 
bool has7(long long x) {
    while(x) {
        if(x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}
 
int maxK; 
vector<int> digits; 
int L;  
 
int DParr[20][25][25][2];
 
int dp (int pos, int rem, int carry, int found) {
    if(pos == L) {
        while(carry > 0) {
            if(carry % 10 == 7)
                found = 1;
            carry /= 10;
        }
        return (rem==0 && found) ? 1 : 0;
    }
    if(DParr[pos][rem][carry][found] != -1)
        return DParr[pos][rem][carry][found];
    int ans = 0;
    int start = (pos == 0 ? 0 : 0), end = (pos == 0 ? 0 : rem);

    for (int x = start; x <= end; x++) {
        if(pos > 0 && x > rem) break;
        int sum = digits[pos] + x + carry;
        int d = sum % 10;
        int newCarry = sum / 10;
        int newFound = found || (d == 7);
        if(dp(pos+1, rem - (pos==0?0:x), newCarry, newFound))
        {
            ans = 1; break;
        }
    }
    DParr[pos][rem][carry][found] = ans;
    return ans;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(has7(n)) {
            cout << 0 << "\n";
            continue;
        }

        int ans = -1;
        for (int k = 1; k < 50; k++){

            maxK = k;
            int M = n - k;
            digits.clear();
            int temp = M;
            while(temp > 0) {
                digits.push_back(temp % 10);
                temp /= 10;
            }
            L = max((int)digits.size(), 1);

            while((int)digits.size() < 12)
                digits.push_back(0);
            L = digits.size();
 
            memset(DParr, -1, sizeof(DParr));
 
            int initFound = (digits[0] % 10 == 7) ? 1 : 0;
            if(dp(0, k, 0, initFound)) { 
                ans = k;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
