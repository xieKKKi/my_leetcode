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
        if(!root)   return {};
        vector<vector<int>> result = {{}};
        vector<int> levelNodeCount = {1, 0};  // 记录每一层有几个节点
        queue<TreeNode*> queueNode;  // 节点队列
        queueNode.push(root);
        while(!queueNode.empty()){
            if(levelNodeCount[result.size()-1] == 0){  // 数到0了，说明这一层结束了，新建一层
                result.push_back({});
                levelNodeCount.push_back(0);
            }
            result[result.size()-1].push_back(queueNode.front()->val);
            if(queueNode.front()->left){
                queueNode.push(queueNode.front()->left);
                levelNodeCount[result.size()] += 1;
            }
            if(queueNode.front()->right){
                queueNode.push(queueNode.front()->right);
                levelNodeCount[result.size()] += 1;
            }
            queueNode.pop();
            levelNodeCount[result.size()-1] -= 1;
        }
        return result;
    }
};
