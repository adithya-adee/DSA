class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> p;
        vector<int> n;

        for (int i{}; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                p.push_back(nums[i]);
            else
                n.push_back(nums[i]);
        }
        for (int i{}, j{}; i < nums.size(); i += 2, j++)
        {
            nums[i] = p[j];
            nums[i + 1] = n[j];
        }
        return nums;
    }
};
