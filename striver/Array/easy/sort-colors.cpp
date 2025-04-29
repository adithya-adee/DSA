// You can use sorting to do this Question,
// But it would be better if you did this method since it contains 0,1 & 2

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int count0{}, count1{}, count2{};
        for (int i{}; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count0++;
            else if (nums[i] == 1)
                count1++;
            else if (nums[i] == 2)
                count2++;
        }
        for (int i{}; i < nums.size(); i++)
        {
            if (count0 != 0)
            {
                nums[i] = 0;
                count0--;
            }
            else if (count1 != 0)
            {
                nums[i] = 1;
                count1--;
            }
            else if (count2 != 0)
            {
                nums[i] = 2;
                count2--;
            }
        }
    }
};