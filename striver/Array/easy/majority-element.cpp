// Optimal Approach : Moore's Voting Algorithm

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count{}, curr{nums[0]};
        int n = nums.size();
        for (int i{}; i < n; i++)
        {
            if (curr == nums[i])
                count++;
            else
                count--;

            if (count == 0)
            {
                curr = nums[i];
                count++;
            }
        }
        return curr;
    }
};

// You can use map data structure to do this question