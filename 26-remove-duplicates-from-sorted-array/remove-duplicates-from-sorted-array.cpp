class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Optimize standard I/O operations for competitive programming
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if (nums.empty()) return 0;
        
        int i = 0; // Points to the last unique element
        
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j]; // Place the unique element in the next position
            }
        }
        
        return i + 1; // Total number of unique elements
    }
};