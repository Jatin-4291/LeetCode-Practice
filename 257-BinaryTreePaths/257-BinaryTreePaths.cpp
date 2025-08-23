// Last updated: 8/23/2025, 2:38:30 PM
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
    void dfs(TreeNode* root, string& temp, vector<string>& ans) {
    int prevSize = temp.size();

    if (!root->left && !root->right) {
        temp += to_string(root->val);
        ans.push_back(temp);
        temp.resize(prevSize);
        return;
    }

    temp += to_string(root->val) + "->";

    if (root->left) dfs(root->left, temp, ans);
    if (root->right) dfs(root->right, temp, ans);
    temp.resize(prevSize);
}

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp ="";
        dfs(root,temp,ans);
        return ans;
    }
};