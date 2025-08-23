// Last updated: 8/23/2025, 2:39:39 PM
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
    void inorder(TreeNode* root,vector<int>& x){
        if(root==nullptr) return;
        inorder(root->left,x);
        x.push_back(root->val);
        inorder(root->right,x);
    }
    void fix(TreeNode* root,int a,int b){
        if (root == nullptr) return;
       if (root->val == a) root->val = b;
        else if (root->val == b) root->val = a;
        fix(root->left,a,b);
        fix(root->right,a,b);
    }
    void recoverTree(TreeNode* root) {
        vector<int> x;
        inorder(root,x);
        vector<int> y=x;
        sort(y.begin(),y.end());
        int a=-1;
        int b=-1;
        for(int i=0;i<y.size();i++){
            if(y[i]!=x[i]){
                if(a==-1){
                    a=x[i];
                }else{
                    b=x[i];
                }
            }
        }
        fix(root,a,b);
    }
};