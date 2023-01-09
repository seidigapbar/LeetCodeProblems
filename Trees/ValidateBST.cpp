# A better recursive solution: 

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
    bool isValidBST(TreeNode* root, TreeNode* left = nullptr, TreeNode* right = nullptr) {
        if(!root){
            return true;
        }
        
        if(left && root->val <= left->val){
            return false;
        } if(right && root->val >= right->val){
            return false;
        }
        
        return isValidBST(root->left, left, root) && isValidBST(root->right, root, right);
    }
};

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
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        return isValidRecursive(root->left, root->val, true, INT_MIN, false) && isValidRecursive(root->right, INT_MAX, false, root->val, true);
    }
    
    bool isValidRecursive(TreeNode* root, int maximalVal, bool maxIsSet, int minimalVal, bool minIsSet){
        if(!root){
            return true;
        }
        
        if((maxIsSet && root->val >= maximalVal)
           || (minIsSet && root->val <= minimalVal)){
            return false;
        }
        int newMax = max(minimalVal, root->val);
        int newMin = min(maximalVal, root->val);
        return isValidRecursive(root->left, newMax, true, minimalVal, minIsSet) && isValidRecursive(root->right, maximalVal, maxIsSet, newMin, true);
    }
};
