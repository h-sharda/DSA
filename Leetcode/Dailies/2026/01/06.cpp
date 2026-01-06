// Problem: 1161. Maximum Level Sum of a Binary Tree (Medium)
// Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans, maxx = INT_MIN, level = 1;
        while (!q.empty()) {
            int sz = q.size(), curr = 0;

            while (sz--) {
                auto ptr = q.front();
                q.pop();
                curr += ptr->val;
                if (ptr->left) q.push(ptr->left);
                if (ptr->right) q.push(ptr->right);
            }

            if (curr > maxx) maxx = curr, ans = level;
            level++;
        }

        return ans;
    }
};