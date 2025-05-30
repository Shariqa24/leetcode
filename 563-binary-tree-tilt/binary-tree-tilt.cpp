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
    int sum=0;
public:
    int findTiltHelper(TreeNode* root) {
        if(!root) return 0;
        int left=findTiltHelper(root->left);
        int right=findTiltHelper(root->right);
        sum+=abs(left-right);
        return left+right+root->val;
    }
    int findTilt(TreeNode* root){
        findTiltHelper(root);
        return sum;
    }
};                            