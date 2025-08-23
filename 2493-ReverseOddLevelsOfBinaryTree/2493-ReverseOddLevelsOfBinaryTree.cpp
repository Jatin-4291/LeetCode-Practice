// Last updated: 8/23/2025, 2:36:34 PM
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);
        bool isRev = false;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> levelNodes;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                levelNodes.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (isRev) {
                int l = 0, r = levelNodes.size() - 1;
                while (l < r) {
                    swap(levelNodes[l]->val, levelNodes[r]->val);
                    l++; r--;
                }
            }

            isRev = !isRev;
        }

        return root;
    }
};
