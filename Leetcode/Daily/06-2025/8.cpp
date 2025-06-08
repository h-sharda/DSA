class Solution {
public:
    void push(vector<int> &ans, int num, int n) {
        if (num % 10 == 0) push(ans, num / 10, n);
        if (num > n) return;
        ans.push_back(num);
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int base = pow(10, (int)log10(n));

        for (int i = base; i < 10*base; i++) push(ans, i, n);

        return ans;
    }
};