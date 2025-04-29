// Optimal Solution

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;
        int preSum = 0, cnt = 0;
        mpp[0] = 1;
        for (int num : nums)
        {
            preSum += num;
            if (mpp.find(preSum - k) != mpp.end())
            {
                cnt += mpp[preSum - k];
            }
            mpp[preSum]++;
        }
        return cnt;
    }
};
