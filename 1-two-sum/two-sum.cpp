#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // Stores {number: index}
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if complement already exists in our map
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }
            
            // Otherwise, store current element and its index
            mp[nums[i]] = i;
        }
        
        return {}; // Guaranteed to find a solution per constraints
    }
};