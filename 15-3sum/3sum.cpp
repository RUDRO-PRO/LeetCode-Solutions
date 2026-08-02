#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// This block unties C and C++ standard streams, 
// significantly boosting I/O speed on LeetCode.
static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Sort the array to enable the two-pointer strategy
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            // Optimization: If the current element is > 0, the sum will never be zero
            if (nums[i] > 0) break;
            
            // Optimization: Skip duplicate elements for the first position
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Optimization: Skip duplicate elements for the second position
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Optimization: Skip duplicate elements for the third position
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    // Move both pointers inward after finding a valid triplet
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    // We need a larger sum, move the left pointer rightward
                    left++;
                } 
                else {
                    // We need a smaller sum, move the right pointer leftward
                    right--;
                }
            }
        }
        
        return result;
    }
};