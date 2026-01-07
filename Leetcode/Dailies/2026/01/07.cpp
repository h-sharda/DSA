// Problem: 1339. Maximum Product of Splitted Binary Tree (Medium)
// Link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long getSum(TreeNode *root) {
        if (!root) return 0;
        return root->val + getSum(root->right) + getSum(root->left);
    }

    long long r(TreeNode* root, long long &ans, long long T) {
        if (!root) return 0;
        long long sum = root->val;
        
        if (root->left) {
            long long L = r(root->left, ans, T);
            ans = max(ans, L * (T - L));
            sum += L;
        }
        if(root->right) {
            long long R = r(root->right, ans, T);
            ans = max(ans, R * (T - R));
            sum += R;
        }

        return sum;
    }

    int maxProduct(TreeNode* root) {
        long long T = getSum(root), ans = INT_MIN;
        r(root, ans, T);
        return ans % MOD;
    }
};