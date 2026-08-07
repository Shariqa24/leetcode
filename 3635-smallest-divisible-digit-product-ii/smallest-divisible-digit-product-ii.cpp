#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper to count prime factors (2, 3, 5, 7) of a number
    vector<int> getFactors(long long t) {
        vector<int> count(10, 0);
        int primes[] = {2, 3, 5, 7};
        for (int p : primes) {
            while (t % p == 0) {
                count[p]++;
                t /= p;
            }
        }
        if (t > 1) return {}; // Contains prime factors > 7
        return count;
    }

    // Helper to find the minimum number of digits needed to satisfy remaining factors
    int getMinLengthNeeded(const vector<int>& req) {
        int c2 = req[2], c3 = req[3], c5 = req[5], c7 = req[7];
        // Combine 3s into 9s
        int n9 = c3 / 2; c3 %= 2;
        // Combine 2s into 8s
        int n8 = c2 / 3; c2 %= 3;
        
        // Combine remaining 2 and 3 into 6
        int n6 = 0;
        if (c2 > 0 && c3 > 0) { n6 = 1; c2--; c3--; }
        
        // Combine remaining 2s into 4s
        int n4 = c2 / 2; c2 %= 2;
        
        // Final standalone digits
        int n7 = c7;
        int n5 = c5;
        int n3 = c3;
        int n2 = c2;
        
        return n9 + n8 + n6 + n4 + n7 + n5 + n3 + n2;
    }

    // Generates the smallest suffix string given the remaining factor requirements and available length
    string getSmallestSuffix(vector<int> req, int rem_len) {
        string suffix = "";
        // Greedy choice from '9' down to '2' to fulfill requirements with largest digits first
        for (int d = 9; d >= 2; --d) {
            if (d == 9) {
                int take = req[3] / 2;
                suffix.append(take, '9');
                req[3] %= 2;
            } else if (d == 8) {
                int take = req[2] / 3;
                suffix.append(take, '8');
                req[2] %= 3;
            } else if (d == 7) {
                suffix.append(req[7], '7');
                req[7] = 0;
            } else if (d == 6) {
                if (req[2] > 0 && req[3] > 0) {
                    suffix.append(1, '6');
                    req[2]--; req[3]--;
                }
            } else if (d == 5) {
                suffix.append(req[5], '5');
                req[5] = 0;
            } else if (d == 4) {
                int take = req[2] / 2;
                suffix.append(take, '4');
                req[2] %= 2;
            } else if (d == 3) {
                suffix.append(req[3], '3');
                req[3] = 0;
            } else if (d == 2) {
                suffix.append(req[2], '2');
                req[2] = 0;
            }
        }
        
        // Fill the remaining length with '1's at the front
        sort(suffix.begin(), suffix.end());
        int ones = rem_len - suffix.length();
        return string(ones, '1') + suffix;
    }

public:
    string smallestNumber(string num, long long t) {
        vector<int> target_req = getFactors(t);
        if (target_req.empty()) return "-1"; // Invalid prime factor found

        int n = num.length();
        
        // Step 1: Check if the string itself can be a valid baseline prefix match
        // Count factors already provided by num (up to the first zero encounter)
        vector<vector<int>> pref_req(n + 1, target_req);
        int first_zero = n;
        
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
            int d = num[i] - '0';
            pref_req[i + 1] = pref_req[i];
            if (d == 2 || d == 4 || d == 6 || d == 8) pref_req[i + 1][2] = max(0, pref_req[i + 1][2] - (d == 2 ? 1 : d == 4 ? 2 : d == 6 ? 1 : 3));
            if (d == 3 || d == 6 || d == 9) pref_req[i + 1][3] = max(0, pref_req[i + 1][3] - (d == 3 ? 1 : d == 6 ? 1 : 2));
            if (d == 5) pref_req[i + 1][5] = max(0, pref_req[i + 1][5] - 1);
            if (d == 7) pref_req[i + 1][7] = max(0, pref_req[i + 1][7] - 1);
        }

        // If num contains no zeros and satisfies target requirements
        if (first_zero == n && pref_req[n][2] == 0 && pref_req[n][3] == 0 && pref_req[n][5] == 0 && pref_req[n][7] == 0) {
            return num;
        }

        // Step 2: Try to match a prefix of length i, increment digit at i, and fill suffix
        for (int i = min(n - 1, first_zero); i >= 0; --i) {
            int start_digit = num[i] - '0' + 1;
            for (int d = start_digit; d <= 9; ++d) {
                vector<int> rem_req = pref_req[i];
                
                // Deduct factors of the new digit d
                if (d == 2 || d == 4 || d == 6 || d == 8) rem_req[2] = max(0, rem_req[2] - (d == 2 ? 1 : d == 4 ? 2 : d == 6 ? 1 : 3));
                if (d == 3 || d == 6 || d == 9) rem_req[3] = max(0, rem_req[3] - (d == 3 ? 1 : d == 6 ? 1 : 2));
                if (d == 5) rem_req[5] = max(0, rem_req[5] - 1);
                if (d == 7) rem_req[7] = max(0, rem_req[7] - 1);

                int rem_len = n - 1 - i;
                if (getMinLengthNeeded(rem_req) <= rem_len) {
                    string ans = num.substr(0, i);
                    ans += to_string(d);
                    ans += getSmallestSuffix(rem_req, rem_len);
                    return ans;
                }
            }
        }

        // Step 3: If no number of length n works, find the minimum length needed > n
        int base_len = n + 1;
        int req_len = getMinLengthNeeded(target_req);
        int final_len = max(base_len, req_len);
        return getSmallestSuffix(target_req, final_len);
    }
};
