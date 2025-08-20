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
unordered_map<int, int> inorderIndex;
int postIdx;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        postIdx = n - 1;
        for(int i = 0; i < n; i ++){
            inorderIndex[inorder[i]] = i;
        }
        return build(postorder, 0 , n - 1);
    }
    TreeNode* build(vector<int>& postorder, int inLeft, int inRight){
        if(inLeft > inRight) return nullptr;
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);
        int idx = inorderIndex[rootVal];
        root->right = build(postorder, idx + 1, inRight);
        root->left = build(postorder, inLeft, idx - 1);
        return root;
    }
};