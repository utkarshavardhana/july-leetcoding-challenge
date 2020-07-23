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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)   return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int level = 0;
        vector<int> t;
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) {
                if(t.empty())   break;
                if(level % 2)   reverse(t.begin(), t.end());
                res.push_back(t);
                t.clear();
                q.push(NULL);
                level++;
                continue;
            }
            t.push_back(node->val);
            if(node->left)  q.push(node->left);
            if(node->right)  q.push(node->right);
        }
        return res;
    }
};
