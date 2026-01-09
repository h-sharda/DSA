// Problem: 865. Smallest Subtree with all the Deepest Nodes (Medium)
// Link: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes

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
    pair<int, TreeNode*> recurse(TreeNode* root) {
        if (!root) return {0, NULL};
        
        auto[a, l] = recurse(root->left);
        auto[b, r] = recurse(root->right);

        if (a > b) return {a + 1, l};
        if (a == b) return {a + 1, root};
        return {b + 1, r};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return recurse(root).second;
    }
};