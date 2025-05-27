class Solution {
public:
    int checkHeight(TreeNode* root, bool& balanced) {
         if (!root) return 0;
int left = checkHeight(root->left, balanced);
int right = checkHeight(root->right, balanced);
        if (abs(left - right) > 1)
            balanced = false;
            return max(left, right) + 1;
    }bool isBalanced(TreeNode* root) {
        bool balanced = true;
        checkHeight(root, balanced);
        return balanced;
    }
};
