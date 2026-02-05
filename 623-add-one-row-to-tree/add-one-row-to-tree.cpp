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
      void dfs(TreeNode* curr,int val,int depth,int currdepth){
        if(!curr)return;

        if(currdepth==depth-1){
              TreeNode* oldleft= curr->left;
              TreeNode* oldright= curr->right;

              curr->left=new TreeNode(val);
              curr-> right=new TreeNode(val);

              curr->left->left= oldleft;
              curr->right->right=oldright;
        return;
        }
        dfs(curr->left,val,depth,currdepth+1);
        dfs(curr->right,val,depth,currdepth+1);
      }


    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
      
        if(depth==1){
         TreeNode * newRoot = new TreeNode(val);
          newRoot->left=root;
          return newRoot;  
        }

        dfs(root,val,depth,1);
        return root;
    }
};