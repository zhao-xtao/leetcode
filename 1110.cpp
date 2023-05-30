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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto item : to_delete) st[item]++;
        if (dfs(root)) ans.push_back(root);
        return ans;
    }

private :
    vector<TreeNode *> ans;
    unordered_map<int, int> st;

    TreeNode *dfs(TreeNode *root) {
        if (root == nullptr) return nullptr;
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        if (!st[root->val]) return root;
        if (root->left) ans.push_back(root->left);
        if (root->right) ans.push_back(root->right);
        return nullptr;
    }
};
