// Last updated: 8/23/2025, 2:37:23 PM
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> mp;
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        while (!q.empty()) {
            auto [node, r, c] = q.front();
            q.pop();
            mp[c].push_back({r, node->val});

            if (node->left)  q.push({node->left,  r + 1, c - 1});
            if (node->right) q.push({node->right, r + 1, c + 1});
        }

        vector<vector<int>> ans;
        for (auto& [key, val] : mp) {
            sort(val.begin(), val.end());
            vector<int> temp;
            for (auto [r, v] : val) {
                temp.push_back(v);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
