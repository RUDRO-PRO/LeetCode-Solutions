#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int p1 = m - 1;         // Pointer to the last valid element in nums1
        int p2 = n - 1;         // Pointer to the last element in nums2
        int p = m + n - 1;      // Pointer to the last available position in nums1

        // Compare elements from the back and place the larger one at index p
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        // If any elements remain in nums2, copy them over.
        // Elements remaining in nums1 are already in their correct places.
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};