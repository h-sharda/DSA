// Problem: 1028. Recover a Tree From Preorder Traversal (Hard)
// Link: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal

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
    int getNum(int &pos, string &str) {
        int ans = 0, n = str.size();
        while (pos < n && isdigit(str[pos])) ans = ans * 10 + (str[pos++] - '0');
        return ans;
    };
    
    int getDash(int &pos, string &str) {
        int ans = 0, n = str.size();
        while (pos < n && str[pos] == '-') pos++, ans++;
        return ans;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0, n = traversal.size();
        TreeNode *root = new TreeNode(getNum(i, traversal));

        stack<pair<int, TreeNode*>> st;
        st.emplace(0, root);

        while (i < n) {
            int d = getDash(i, traversal), val = getNum(i, traversal);

            int dash = st.top().first;
            while (st.top().first >= d) st.pop();
            TreeNode *neww = new TreeNode(val);

            if (st.top().second->left) st.top().second->right = neww;
            else st.top().second->left = neww;

            st.emplace(d, neww);
        }

        
        return root;
    }
};