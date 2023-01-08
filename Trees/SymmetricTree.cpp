# Looked the idea of recursion up

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
    bool isSymmetric(TreeNode* root) {
        return root ? helpSymmetric(root->left, root->right) : true;
    }
    
    bool helpSymmetric(TreeNode* left, TreeNode* right){
        if(left == nullptr || right == nullptr){
            return left == right;
        }
        if (left->val == right->val){
            return (helpSymmetric(left->right, right->left) && helpSymmetric(left->left, right->right));
        }
        return false;
    }
};

