#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2", "bmi", "bmi2", "lzcnt", "popcnt")

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(closestSum - target);

        for (int i = 0; i < n - 2; ++i) {
            // Optimization: Skip duplicate elements for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // Exact match found, return immediately
                if (currentSum == target) {
                    return target;
                }

                int currentDiff = abs(currentSum - target);
                if (currentDiff < minDiff) {
                    minDiff = currentDiff;
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return closestSum;
    }
};