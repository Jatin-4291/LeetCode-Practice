// Last updated: 8/30/2025, 1:25:36 PM
class FindElements {
public:
    TreeNode* main;
    std::unordered_set<int> values; 

    void recover(TreeNode* root, int value) {
        if (!root) return;
        root->val = value;
        values.insert(value);
        recover(root->left, 2 * value + 1);
        recover(root->right, 2 * value + 2);
    }

    FindElements(TreeNode* root) {
        main = root;
        if (main) recover(main, 0);
    }

    bool find(int target) {
        return values.count(target);
    }
};
