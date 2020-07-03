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
    
    void _levelOrderBottom(TreeNode* root, queue<TreeNode*> temp, vector<vector<int> > &res) {
        if(temp.empty())    return;
        queue<TreeNode*> q;
        vector<int> v;
        while(!temp.empty()) {
            TreeNode* node = temp.front();
            v.push_back(node->val);
            if(node->left)  q.push(node->left);
            if(node->right)  q.push(node->right);
            temp.pop();
        }
        res.push_back(v);
        _levelOrderBottom(root, q, res);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        queue<TreeNode*> temp;
        if(root)    temp.push(root);
        _levelOrderBottom(root, temp, res);
        reverse(res.begin(), res.end());
        return res;
    }
};
