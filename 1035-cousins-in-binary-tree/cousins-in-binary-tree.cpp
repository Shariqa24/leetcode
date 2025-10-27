 class Solution {
public:
    TreeNode* x_parent = nullptr;
    TreeNode* y_parent = nullptr;
    int x_depth = -1, y_depth = -1;

    void dfs(TreeNode* node, TreeNode* parent, int depth, int x, int y) {
        if (!node) return;
        if (node->val == x) {
            x_parent = parent;
            x_depth = depth;
        }
        if (node->val == y) {
            y_parent = parent;
            y_depth = depth;
        }
        if (x_depth != -1 && y_depth != -1) return;
        dfs(node->left, node, depth + 1, x, y);
        dfs(node->right, node, depth + 1, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, nullptr, 0, x, y);
        return (x_depth == y_depth) && (x_parent != y_parent);
    }
};
