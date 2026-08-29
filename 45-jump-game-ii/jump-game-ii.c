#include <stdio.h>

int jump(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;
    
    int jumps = 0;
    int current_end = 0;
    int farthest = 0;
    
    for (int i = 0; i < numsSize - 1; i++) {
        // Track the farthest point reachable from index i
        if (i + nums[i] > farthest) {
            farthest = i + nums[i];
        }
        
        // Reached the boundary of the current jump
        if (i == current_end) {
            jumps++;
            current_end = farthest;
            
            // Early exit if the end is already reachable
            if (current_end >= numsSize - 1) {
                break;
            }
        }
    }
    
    return jumps;
}