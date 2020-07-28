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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
private:
    TreeNode* helper(vector<int>& inorder,int i,int j,vector<int>& postorder,int ii,int jj) { 
        if(i >= j || ii >= jj)  return NULL;
        int mid = postorder[jj - 1];
        auto f = find(inorder.begin() + i,inorder.begin() + j,mid);
        int dis = f - inorder.begin() - i;
        TreeNode* root = new TreeNode(mid);
        root -> left = helper(inorder,i,i + dis,postorder,ii,ii + dis);
        root -> right = helper(inorder,i + dis + 1,j,postorder,ii + dis,jj - 1);
        return root;
    }
};
