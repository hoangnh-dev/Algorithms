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
bool check(TreeNode* n1, TreeNode* n2){
    if(n1 == nullptr && n2 == nullptr) return true;
    if(n1 == nullptr || n2 == nullptr || n1->val != n2->val) return false;
    return check(n1->left, n2->right) && check(n2->left, n1->right);
}
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* t1 = root->left;
        TreeNode* t2 = root->right;
        return check(t1, t2);
    }
};