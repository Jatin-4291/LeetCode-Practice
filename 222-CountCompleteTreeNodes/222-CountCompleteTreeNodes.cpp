// Last updated: 8/23/2025, 2:38:44 PM
class Solution {
public:
    int findLeftH(TreeNode* root){
        int count = 0;
        while (root != nullptr) {
            count++;
            root = root->left;
        }
        return count;
    }

    int findRightH(TreeNode* root){
        int count = 0;
        while (root != nullptr) {
            count++;
            root = root->right;
        }
        return count;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lh = findLeftH(root);
        int rh = findRightH(root);

        if (lh == rh) {
            return (1LL << lh) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
