class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;

        string word(len, '?');

        // Step 1: Apply 'T' constraints
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }

        // Step 2: Fill remaining with 'a'
        for (char &c : word) {
            if (c == '?') c = 'a';
        }

        // Step 3: Handle 'F'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool fixed = false;

                    // Try to break from rightmost
                    for (int j = m - 1; j >= 0; j--) {
                        int pos = i + j;

                        char original = word[pos];

                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c == original) continue;

                            word[pos] = c;

                            // Check if it still satisfies all T constraints
                            bool valid = true;

                            for (int k = 0; k < n; k++) {
                                if (str1[k] == 'T') {
                                    for (int x = 0; x < m; x++) {
                                        if (word[k + x] != str2[x]) {
                                            valid = false;
                                            break;
                                        }
                                    }
                                    if (!valid) break;
                                }
                            }

                            if (valid) {
                                fixed = true;
                                break;
                            }

                            word[pos] = original;
                        }

                        if (fixed) break;
                    }

                    if (!fixed) return "";
                }
            }
        }

        return word;
    }
};