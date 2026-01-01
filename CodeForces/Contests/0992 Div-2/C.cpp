#include <bits/stdc++.h>
using namespace std;

// Precompute factorials
vector<long long> precomputeFactorials(int n) {
    vector<long long> fact(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fact[i] = fact[i - 1] * i;
        if (fact[i] < 0) fact[i] = LLONG_MAX; 
    }
    return fact;
}

// Directly generate the k-th permutation in descending order
vector<int> generateKthPermutationDescending(int n, long long k, const vector<long long>& fact) {
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1); // nums = [1, 2, ..., n]
    reverse(nums.begin(), nums.end()); // Descending order
    
    vector<int> result;
    k--; // Convert to 0-based index
    
    while (!nums.empty()) {
        int group_size = fact[nums.size() - 1];
        int index = k / group_size; // Find which group the k-th permutation belongs to
        result.push_back(nums[index]);
        nums.erase(nums.begin() + index);
        k %= group_size;
    }
    
    return result;
}

// Function to find the k-th permutation with maximum S(p)
vector<int> findKthMaxSPermutation(int n, long long k) {
    if (n > 20) return {-1}; // Handle large n separately for practical reasons

    vector<long long> fact = precomputeFactorials(n);

    long long total_perms = fact[n];
    if (k > total_perms) return {-1};

    return generateKthPermutationDescending(n, k, fact);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<int> result = findKthMaxSPermutation(n, k);
        if (result.size() == 1 && result[0] == -1) {
            cout << "-1" << endl;
        } else {
            for (int num : result) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
