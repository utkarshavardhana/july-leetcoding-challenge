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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        int ans = 0;
        while(!q.empty()) {
            int s = q.size();
            //reduce the index
            if(s == 1) q.front().second = 1;
            ans = max(ans, q.back().second - q.front().second + 1);
            for(int i = 0; i < s; ++i) {
                auto cur = q.front();
                q.pop();
                if(cur.first->left) q.push(make_pair(cur.first->left, cur.second * 2 - 1));
                if(cur.first->right) q.push(make_pair(cur.first->right, cur.second * 2));
            }
        }
        return ans;
    }
};
