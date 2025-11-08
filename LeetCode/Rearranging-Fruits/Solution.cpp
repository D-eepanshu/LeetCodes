class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
      
        // Count the frequency difference between basket1 and basket2
        // Positive value means excess in basket1, negative means excess in basket2
        unordered_map<int, int> frequencyDifference;
        for (int i = 0; i < n; ++i) {
            frequencyDifference[basket1[i]]++;
            frequencyDifference[basket2[i]]--;
        }
      
        // Track the minimum value across both baskets
        int minValue = INT_MAX;
      
        // Store the values that need to be swapped
        vector<int> valuesToSwap;
      
        // Process each unique value and its frequency difference
        for (auto& [value, difference] : frequencyDifference) {
            // If the difference is odd, it's impossible to balance the baskets
            if (difference % 2 != 0) {
                return -1;
            }
          
            // Add half of the absolute difference to swap list
            // This represents how many of this value need to be moved
            int swapCount = abs(difference) / 2;
            for (int i = 0; i < swapCount; ++i) {
                valuesToSwap.push_back(value);
            }
          
            // Update the minimum value found
            minValue = min(minValue, value);
        }
      
        // Sort values to swap in ascending order
        sort(valuesToSwap.begin(), valuesToSwap.end());
      
        // Calculate minimum cost by swapping the first half of sorted values
        // For each swap, we can either:
        // 1. Swap directly (cost = smaller value)
        // 2. Use the minimum value as intermediate (cost = 2 * minValue)
        int totalSwaps = valuesToSwap.size();
        long long totalCost = 0;
      
        for (int i = 0; i < totalSwaps / 2; ++i) {
            totalCost += min(valuesToSwap[i], minValue * 2);
        }
      
        return totalCost;
    }
};