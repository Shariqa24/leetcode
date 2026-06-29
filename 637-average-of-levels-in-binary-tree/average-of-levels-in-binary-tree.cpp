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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_count = q.size();
            long long Level_sum = 0;

            for (int i = 0; i < level_count; i++) {
                TreeNode* x = q.front();
                q.pop();

                Level_sum += x->val;

                if (x->left) {
                    q.push(x->left);
                }

                if (x->right) {
                    q.push(x->right);
                }
            }
            res.push_back((double)Level_sum / level_count);
        }

        return res;
    }
};