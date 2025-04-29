class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        if (nums.empty())
            return 0; // Handle empty array
        int i = 0;
        int j = i + 1;

        for (; j < nums.size(); j++)
        {
            if (nums[i] != nums[j])
            {
                swap(nums[i + 1], nums[j]);
                i++;
            }
        }

        return i + 1;
    }
};