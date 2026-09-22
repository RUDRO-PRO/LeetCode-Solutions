class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0; // Base case
        
        int left = 1, right = x;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If mid * mid == x, we found the exact square root
            if (mid == x / mid) {
                return mid;
            } 
            // If mid * mid < x, the answer could be mid or greater
            else if (mid < x / mid) {
                left = mid + 1;
            } 
            // If mid * mid > x, the answer must be smaller than mid
            else {
                right = mid - 1;
            }
        }
        
        // When the loop ends, 'right' will hold the truncated square root
        return right;
    }
};