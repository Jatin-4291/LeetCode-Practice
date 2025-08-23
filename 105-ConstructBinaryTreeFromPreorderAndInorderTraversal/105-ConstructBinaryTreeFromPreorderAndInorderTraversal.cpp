// Last updated: 8/23/2025, 2:39:32 PM
class Solution {
public:
    TreeNode* solve(unordered_map<int,int>& inoMap,
                    vector<int>& inorder, vector<int>& preorder,
                    int inStart, int inEnd,
                    int preStart, int preEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inoMap[root->val];
        int len = inRoot - inStart;

        root->left = solve(inoMap, inorder, preorder,
                           inStart, inRoot - 1,
                           preStart + 1, preStart + len);

        root->right = solve(inoMap, inorder, preorder,
                            inRoot + 1, inEnd,
                            preStart + len + 1, preEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inoMap;
        for (int i = 0; i < inorder.size(); i++) {
            inoMap[inorder[i]] = i;
        }
        return solve(inoMap, inorder, preorder,
                     0, inorder.size() - 1,
                     0, preorder.size() - 1);
    }
};
