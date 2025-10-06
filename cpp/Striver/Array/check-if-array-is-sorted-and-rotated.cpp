class Solution
{
public:
    bool check(vector<int> &nums)
    {
        size_t len{nums.size()};
        int count{};
        for (size_t i{}; i < len; i++)
        {
            if (nums[i] > nums[(i + 1) % len])
                ++count;
        }
        return count <= 1;
    }
};

int main()
{

    vector<int> nums{1, 2, 3, 4, 5, 6};
    vector<int> temp;
    int index = 2;
    for (int i{}; i < nums.length(); i++)
    {
        if (i >= index)
        {
            nums[i - index] = nums[i];
        }
        else
        {
            temp.push_back(nums[i]);
        }
    }
    for (int j = nums.length - 1; j > nums.length - index - 1; j--)
    {
        nums[j] = temp[];
    }
}