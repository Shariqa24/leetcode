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
vector<int>inorder;
    void Inorder(TreeNode* root) {
        if(root==NULL) return ;
        Inorder(root->left);
        inorder.push_back(root->val);
        Inorder(root->right);
    }
    TreeNode* build(int start,int end){
        if(start>end) return NULL;
         
         int mid=(start+end)/2;
         TreeNode* root=new TreeNode(inorder[mid]);
         root->left=build(start,mid-1);
         root->right=build(mid+1,end);
         return root;
    }
         TreeNode* balanceBST(TreeNode* root){
            if(root==NULL) return NULL;
            Inorder(root);
            return build(0,inorder.size()-1);
       
    }
};