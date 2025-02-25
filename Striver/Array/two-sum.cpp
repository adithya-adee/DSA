class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            int c = nums[i];
            int rem = target - c;
            if (mpp.find(rem) != mpp.end())
                return {i, mpp[rem]};
            mpp[nums[i]] = i;
        }
        return {-1, -1};
    }
};