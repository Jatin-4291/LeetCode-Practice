// Last updated: 8/23/2025, 2:37:03 PM
class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        int count = 0;

        while (!q.empty()) {
            auto [node, maxSoFar] = q.front();
            q.pop();

            if (node->val >= maxSoFar) count++;

            int newMax = max(maxSoFar, node->val);

            if (node->left) q.push({node->left, newMax});
            if (node->right) q.push({node->right, newMax});
        }

        return count;
    }
};
