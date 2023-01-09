# TODO: find a proper solution...


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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int halfOfArray = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[halfOfArray]);

        int leftLeft = 0, leftRight = halfOfArray - 1, rightLeft = halfOfArray + 1, rightRight = nums.size();
        
        reversiveAddition(make_pair(leftLeft, leftRight), make_pair(rightLeft, rightRight), nums, root); 
        return root;
    }

    void reversiveAddition(pair<int, int> leftRange, pair<int, int> rightRange, vector<int>& nums, TreeNode* parent){
        TreeNode *ptr_left = parent, *ptr_right = parent;
        
        if(leftRange.first < leftRange.second){
            int leftMiddle = (leftRange.second + leftRange.first) / 2;
            ptr_left->left = new TreeNode(nums[leftMiddle]);
            ptr_left = ptr_left->left;
            reversiveAddition(make_pair(leftRange.first, leftMiddle - 1), make_pair(leftMiddle + 1, leftRange.second), nums, ptr_left);
        } else if(leftRange.first == leftRange.second){
            ptr_left->left = new TreeNode(nums[leftRange.first]);
        }
        
        if(rightRange.second > rightRange.first){
            int rightMiddle = (rightRange.second + rightRange.first) / 2;
            ptr_right->right = new TreeNode(nums[rightMiddle]);
            ptr_right = ptr_right->right;
            reversiveAddition(make_pair(rightRange.first, rightMiddle - 1), make_pair(rightMiddle + 1, rightRange.second), nums, ptr_right);
        } else if(rightRange.first < nums.size() && rightRange.first == rightRange.second){
            ptr_right->right = new TreeNode(nums[rightRange.first]);
        }
        
        
    }
};
