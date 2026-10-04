class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {

            if (c == '(') {
                low++;
                high++;
            }

            else if (c == ')') {
                low--;
                high--;
            }

            else { // '*'
                low--;
                high++;
            }

            // We cannot have negative minimum opens
            low = max(0, low);

            // Even maximum opens became negative
            if (high < 0) {
                return false;
            }
        }

        // We need some possibility with exactly 0 opens
        return low == 0;
    }
};