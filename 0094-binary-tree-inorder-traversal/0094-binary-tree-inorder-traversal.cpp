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
private:
void addArray(TreeNode* root, vector<int>& result){
    if (root == nullptr) return;

    addArray(root->left, result);
    result.push_back(root->val);
    addArray(root->right, result);
}
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        addArray(root, result);
        return result;
    }
};