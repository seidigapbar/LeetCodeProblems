# Improved recursive solution: 

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        recursivePushToArray(root, 0, ans);
        return ans;
    }
    
    void recursivePushToArray(TreeNode* ptr, int level, vector<vector<int>> &arr){
        if(!ptr){
            return;
        }
        
        if (arr.size() <= level){
            arr.push_back(vector<int>());
        }
        
        arr[level].push_back(ptr->val);
        
        recursivePushToArray(ptr->left, level+1, arr);
        recursivePushToArray(ptr->right, level+1, arr);
    }
};

# My ugly recursion: 

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root){
            return ans;
        }
        
        vector<int> tmp;
        ans.push_back(tmp);
        ans[0].push_back(root->val);
        
        return orderRecursion(root->left, root->right, ans, 0);
    }
    
    vector<vector<int>> orderRecursion(TreeNode* left, TreeNode* right, vector<vector<int>> &ans, int level){
        if(left == nullptr && right == nullptr){
            return ans;
        } else if(left == nullptr){
            pushToArray(ans, level+1);
            ans[level+1].push_back(right->val);
            return orderRecursion(right->left, right->right, ans, level+1);
        } else if(right == nullptr){
            pushToArray(ans, level+1);
            ans[level+1].push_back(left->val);
            return orderRecursion(left->left, left->right, ans, level+1);
        } else{
            pushToArray(ans, level+1);
            ans[level+1].push_back(left->val);
            ans[level+1].push_back(right->val);
            ans = orderRecursion(left->left, left->right, ans, level+1);
            return orderRecursion(right->left, right->right, ans, level+1);
        }
    }
    
    void pushToArray(vector<vector<int>> &arr, int level){
        if(arr.size() <= level){
            vector<int> tmp;
            arr.push_back(tmp);
        }
    }
};


# BFS:

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root){
            return ans;
        }
        
        int level = 0;
        vector<int> tmp;
        
        TreeNode* ptr;
        queue<pair<TreeNode*, int>> vals;
        ptr = root;
        vals.push(make_pair(ptr, level));
        
        while(!vals.empty()){
            ptr = vals.front().first;
            level = vals.front().second;
            vals.pop();
            if(ans.size() <= level){
                ans.push_back(tmp);
            }
            ans[level].push_back(ptr->val);
            if(ptr->left){
                vals.push(make_pair(ptr->left, level + 1));
            } if(ptr->right){
                vals.push(make_pair(ptr->right, level + 1));
            }
        }
        
        return ans;
    }
};
