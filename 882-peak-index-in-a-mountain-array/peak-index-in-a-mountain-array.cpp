class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int st = 0, end = A.size() - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (mid > 0 && mid < A.size() - 1 && A[mid - 1] < A[mid] && A[mid] > A[mid + 1]) {
                return mid;
            } else if (mid < A.size() - 1 && A[mid] < A[mid + 1]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};
