// Interview Bit: Subarray with given XOR (Medium)
// link: https://www.interviewbit.com/problems/subarray-with-given-xor/

#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

class Solution {
public:
    int solve(vector<int> &A, int B);
};

int Solution::solve(vector<int> &A, int B) {
    int xorr = 0, n = A.size(), ans =0;
    unordered_map <int, int> umap;
    
    for (int i =0; i<n; i++){
        xorr ^= A[i];
        
        if ( xorr == B) ans++;
        int target = B^xorr;
        
        ans += umap[target];
        
        umap[xorr]++;
    }
    
    return ans;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        int n, B;
        cin >> n >> B;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.solve(A, B) << "\n";
    }
    return 0;
}