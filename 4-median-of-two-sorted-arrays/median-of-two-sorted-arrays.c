#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the smaller array to minimize binary search steps
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size;
    int n = nums2Size;
    int low = 0, high = m;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;

        // If partitionX is 0, maxLeftX is negative infinity
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        // If partitionX is m, minRightX is positive infinity
        int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

        // If partitionY is 0, maxLeftY is negative infinity
        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        // If partitionY is n, minRightY is positive infinity
        int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

        // Check if we have found the correct partition
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            // If total elements is even
            if ((m + n) % 2 == 0) {
                double leftMax = (maxLeftX > maxLeftY) ? maxLeftX : maxLeftY;
                double rightMin = (minRightX < minRightY) ? minRightX : minRightY;
                return (leftMax + rightMin) / 2.0;
            } 
            // If total elements is odd
            else {
                return (maxLeftX > maxLeftY) ? maxLeftX : maxLeftY;
            }
        } 
        else if (maxLeftX > minRightY) {
            // We are too far right on nums1, move left
            high = partitionX - 1;
        } 
        else {
            // We are too far left on nums1, move right
            low = partitionX + 1;
        }
    }

    return 0.0;
}