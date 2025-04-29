class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);

        int maxSum{INT_MIN}, sum{};
        for (int i{}; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > maxSum)
                maxSum = sum;
            if (sum < 0)
                sum = 0;
        }
        return maxSum;
    }
};

// Method 2: Brute Force Approach
// This is done by taking all the subset of the array and checking the maximum sum from each subarray