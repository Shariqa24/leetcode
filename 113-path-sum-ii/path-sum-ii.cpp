class Solution {
public:
    void collectPaths(TreeNode* root, int targetSum,
                      vector<int>& temp,
                      vector<vector<int>>& result) {

        if (root == NULL)return;
        temp.push_back(root->val);
      if (root->left == NULL && root->right == NULL &&
            targetSum == root->val) {
            result.push_back(temp);
        }
        collectPaths(root->left, targetSum - root->val, temp, result);
        collectPaths(root->right, targetSum - root->val, temp, result);
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        collectPaths(root, targetSum, temp, result);
        return result;
    }
};
