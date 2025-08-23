// Last updated: 8/23/2025, 2:37:46 PM
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long first = -1, last = -1;
            long long minIdx = q.front().second; 

            for (int i = 0; i < size; i++) {
                auto [node, idx] = q.front();
                q.pop();

                idx -= minIdx; 
                if (first == -1) first = idx;
                last = idx;

                if (node->left) q.push({node->left, 2 * idx + 1});
                if (node->right) q.push({node->right, 2 * idx + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return (int)ans;
    }
};
