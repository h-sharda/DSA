#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t; 
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int j = 0; j < n; j++){
            cin >> a[j];
        }
 
        // possible[j] will become true if some network gives a[j] correctly.
        vector<bool> possible(n, false);
        // For each network count how many positions match a.
        vector<int> cnt(m, 0);
 
        // Store all neural network answer arrays.
        vector<vector<string>> b(m, vector<string>(n));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cin >> b[i][j];
            }
        }
 
        // Count "correct" positions for each network and mark positions that can be fixed.
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(b[i][j] == a[j]){
                    cnt[i]++;
                    possible[j] = true;
                }
            }
        }
 
        // If some position j is not “fixable” by any network then answer is impossible.
        bool ok = true;
        for (int j = 0; j < n; j++){
            if(!possible[j]){
                ok = false;
                break;
            }
        }
 
        if(!ok){
            cout << -1 << "\n";
            continue;
        }
 
        // Determine the maximum number of positions any network gets right.
        int best = 0;
        for (int i = 0; i < m; i++){
            best = max(best, cnt[i]);
        }
 
        // The minimum number of operations needed is given by:
        //   ops = 3*n - 2 * (best)
        // Explanation:
        //   - You have to perform n neural operations (one per position).
        //   - For each position that isn’t "covered" safely by a single network (that is, not among the best-covered ones)
        //     you eventually must perform an extra removal operation.
        //   - A careful worst-case analysis (and some adversary arguments) shows that
        //       total_ops = 3n - 2*best.
        int ans = 3 * n - 2 * best;
        cout << ans << "\n";
    }
 
    return 0;
}
