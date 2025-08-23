// Last updated: 8/23/2025, 2:39:29 PM
class Solution {
public:
    int solve(TreeNode* root) {
        if (!root) return 0;
        int left = solve(root->left);
        if (left == -1) return -1;
        int right = solve(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return solve(root) != -1;
    }
};
