class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        string result = "";

        while (i >= 0 || j >= 0 || carry == 1) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            char bit = (sum % 2) + '0';
            result.insert(result.begin(), bit);  

            carry = sum / 2;
        }

        return result;
    }
};
