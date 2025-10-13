class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;
        inorder(root1, list1);
        inorder(root2, list2);

        vector<int> merged;
        int i = 0, j = 0;

        while (i < list1.size() && j < list2.size()) {
            if (list1[i] < list2[j]) merged.push_back(list1[i++]);
            else merged.push_back(list2[j++]);
        }
        while (i < list1.size()) merged.push_back(list1[i++]);
        while (j < list2.size()) merged.push_back(list2[j++]);

        return merged;
    }
};
