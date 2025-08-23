// Last updated: 8/23/2025, 2:39:31 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(unordered_map<int,int>& inoMap,vector<int>& inorder, vector<int>& postorder,int inStart,int inEnd,int postStart,int postEnd){
        if(inStart>inEnd || postStart>postEnd) return nullptr;
        TreeNode* root=new TreeNode(postorder[postEnd]);
        int inRoot=inoMap[root->val];
        int len=inRoot-inStart;
        root->left=solve(inoMap,inorder,postorder,inStart,inRoot-1,postStart,postStart+len-1);
        root->right=solve(inoMap,inorder,postorder,inRoot+1,inEnd,postStart+len,postEnd-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inoMap;
        for(int i=0;i<inorder.size();i++){
            inoMap[inorder[i]]=i;
        }
        return solve(inoMap,inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);

    }
};