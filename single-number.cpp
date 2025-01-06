// Optimal Solution
class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        int n = nums.size();
        int f1 = 0;

        for (auto num : nums)
        {
            f1 ^= num;
        }

        return f1;
    }
};

/*
class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        int n = nums.size();

        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
        }
        for (auto it : mpp)
        {
            if (it.second == 1)
                return it.first;
        }

        return -1;
    }
};
*/