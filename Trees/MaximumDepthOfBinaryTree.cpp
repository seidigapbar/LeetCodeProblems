# After I got a hint from my friend that I could use recursion:

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
    int maxDepth(TreeNode* root, int depth = 0) {
        
        if(!root){
            return depth;
        }
        
        return max(maxDepth(root->left, depth+1), maxDepth(root->right, depth+1));
    }
};

# Solution before practicing BFS or DFS at all

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
    int maxDepth(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
        stack<pair<TreeNode*, int>> NodeToDepth;
        TreeNode* ptr = root;
        size_t depth = 1, maxd = 0;
        
        NodeToDepth.push(make_pair(ptr, depth));
        
        while(!NodeToDepth.empty()){
            ptr = NodeToDepth.top().first;
            cout<<ptr->val<<endl;
            depth = NodeToDepth.top().second;
            maxd = max(maxd, depth);
            NodeToDepth.pop();
            if (ptr->left){
                NodeToDepth.push(make_pair(ptr->left, depth + 1));
            }
            if (ptr->right){
                NodeToDepth.push(make_pair(ptr->right, depth + 1));
            }
        }
        
        return maxd;
    }
};
