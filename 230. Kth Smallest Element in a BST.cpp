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
    int result;
    int K;
public:
    void inorder(TreeNode* root){
        if(K && root->left)
            inorder(root->left);
        if(K){
            if(--K == 0)
            {
                result = root->val;
                return;
            }
        }
        if(K && root->right)
            inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        K = k;
        inorder(root);
        return result;
    }
};
