// Problem: 1261. Find Elements in a Contaminated Binary Tree (Medium)
// Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree

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
class FindElements {
public:
    unordered_set<int> uset;

    void populate (TreeNode* root) {
        if (root == NULL ) return;
        uset.insert(root->val);
        if (root->left != NULL) {
            root->left->val = 2*(root->val) + 1;
            populate(root->left);
        }
        if (root->right != NULL) {
            root->right->val = 2*(root->val) + 2;
            populate(root->right);
        }
    }

    FindElements(TreeNode* root) {
        root->val = 0;
        uset.insert(0);
        populate(root);
    }
    
    bool find(int target) {
        return uset.contains(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */