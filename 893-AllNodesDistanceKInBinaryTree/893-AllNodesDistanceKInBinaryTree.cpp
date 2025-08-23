// Last updated: 8/23/2025, 2:37:33 PM
class Solution {
public:
    void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* p) {
        parent[root] = p;
        if (root->left) findParent(root->left, parent, root);
        if (root->right) findParent(root->right, parent, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        findParent(root, parent, nullptr);

        vector<int> ans;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            if (dist == k) {
                for (int i = 0; i < size; i++) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (parent[node] && !visited.count(parent[node])) {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
            }
            dist++;
        }
        return ans;
    }
};
