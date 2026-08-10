class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        // last[j] = position in word1 where word2[j]
        // is matched in the right-to-left greedy matching.
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {

            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }

            i--;
        }

        vector<int> ans(m);

        bool canChange = true;

        j = 0;

        for (i = 0; i < n && j < m; i++) {

            // Case 1: exact match
            if (word1[i] == word2[j]) {

                ans[j] = i;
                j++;
            }

            // Case 2: use our one allowed mismatch
            else if (canChange &&
                     (j == m - 1 || i < last[j + 1])) {

                ans[j] = i;
                j++;

                canChange = false;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};