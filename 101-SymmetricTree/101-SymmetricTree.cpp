// Last updated: 8/23/2025, 2:39:38 PM
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true; 

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> temp;
            int size = q.size();

            for (int k = 0; k < size; k++) {
                TreeNode* node = q.front();
                q.pop();

                if (node) {
                    temp.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                } else {
                    temp.push_back(-101); 
                }
            }

            int i = 0, j = temp.size() - 1;
            while (i < j) {
                if (temp[i] != temp[j]) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
};
