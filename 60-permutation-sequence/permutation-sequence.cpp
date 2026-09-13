#include <string>
#include <vector>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::vector<int> numbers;
        int fact = 1;
        
        // Prepare list of numbers [1, 2, ..., n]
        // and compute (n-1)!
        for (int i = 1; i < n; ++i) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        
        // Convert k to 0-based index
        --k;
        
        std::string result = "";
        
        while (true) {
            // Determine which number to pick
            int index = k / fact;
            result += std::to_string(numbers[index]);
            
            // Remove the picked number
            numbers.erase(numbers.begin() + index);
            
            if (numbers.empty()) {
                break;
            }
            
            // Update k and the factorial base for the next position
            k %= fact;
            fact /= numbers.size();
        }
        
        return result;
    }
};