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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        function<void(TreeNode*, string)> dfs = [&](TreeNode* node, string path){
            if(!node) return;
            if(!path.empty()) path += "->";
            path += to_string(node->val);
            if(!node->left &&  !node->right){
                res.push_back(path);
                return;
            }
            dfs(node->left, path);
            dfs(node->right, path);
        };
        dfs(root,"");
        return res;
    }
};