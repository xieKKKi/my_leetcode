/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private: 
    TreeNode* result;
public:
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || result) return false;
        bool isRoot = (root == p || root == q);
        bool isLeft = dfs(root->left, p, q);
        bool isRight = dfs(root->right, p, q);
        if((isRoot && (isLeft || isRight)) || (isLeft && isRight))
            result = root;
        return isRoot || isLeft || isRight;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        result = NULL;
        dfs(root, p, q);
        return result;
    }
};
