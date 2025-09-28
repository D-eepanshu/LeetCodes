class Solution {
public:
    int largestPerimeter(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::greater<int>()); // Sort in descending order

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i + 1] + nums[i + 2] > nums[i]) {
                // Valid triangle found
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }

        return 0; // No valid triangle
    }
};
