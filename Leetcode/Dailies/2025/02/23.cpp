// Problem: 889. Construct Binary Tree from Preorder and Postorder Traversal (Medium)
// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal

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
    TreeNode* buildTree(int a, int b, int c, int d, vector<int> &preorder, unordered_map<int, int> &umap) {
        if (b < a || d < c) return NULL;
        if (b == a || d == c) return new TreeNode(preorder[a]);

        TreeNode *root = new TreeNode(preorder[a]);
        
        int len = umap[preorder[a + 1]] - c + 1;
        root->left = buildTree(a + 1, a + len, c, c + len - 1, preorder, umap);
        root->right = buildTree(a + len + 1, b, c + len, d, preorder, umap);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> umap;
        int n = preorder.size();

        for (int i = 0; i< n; i++) umap[postorder[i]] = i;
        return buildTree(0, n-1, 0, n-1, preorder, umap);
    }
};