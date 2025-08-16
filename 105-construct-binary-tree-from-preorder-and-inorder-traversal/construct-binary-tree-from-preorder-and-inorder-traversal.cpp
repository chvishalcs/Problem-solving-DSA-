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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for(int i = 0; i < inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        int preIndex = 0;
        return build(preorder, inMap, preIndex, 0 , inorder.size() - 1);
    }
    private:
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inMap, int& preIndex, int inStart, int inEnd){
        if(inStart > inEnd) return nullptr;
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int inIndex = inMap[rootVal];
        root->left = build(preorder, inMap, preIndex, inStart, inIndex - 1);
        root->right = build(preorder, inMap, preIndex, inIndex + 1, inEnd);
        return root;
    }
};