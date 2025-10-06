// Optimal Approach : Extended Moore's Algorithm TimeC O(n) SpaceC O(1)
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        size_t count1{}, count2{}, n{nums.size()};
        int element1{INT_MIN}, element2{INT_MIN};
        int majority = static_cast<int>(floor(n / 3));

        for (int &num : nums)
        {
            if (num == element1)
            {
                count1++;
            }
            else if (num == element2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                element1 = num;
                count1++;
            }
            else if (count2 == 0)
            {
                element2 = num;
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        vector<int> result;
        count1 = 0;
        count2 = 0;
        for (int num : nums)
        {
            if (num == element1)
            {
                count1++;
            }
            if (num == element2)
            {
                count2++;
            }
        }

        if (count1 > majority)
        {
            result.push_back(element1);
        }
        if (count2 > majority)
        {
            result.push_back(element2);
        }
        return result;
    }
};

/*
This gives 0ms runtime in Leetcode But space complexity is O(n) and Time Complexity is O(2n) to be specific
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> res;
        unordered_map<int, int> mpp;
        size_t n = nums.size();
        for (int &x : nums)
            mpp[x]++;

        int tar = static_cast<int>(floor(n / 3));
        for (size_t i{}; i < n; i++)
        {
            if (mpp[nums[i]] > tar)
            {
                res.push_back(nums[i]);
                mpp[nums[i]] = 0;
            }
        }
        return res;
    }
};
*/