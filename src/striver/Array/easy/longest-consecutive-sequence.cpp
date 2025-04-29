// Optimal Approach
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> st;
        for (int &it : nums)
            st.insert(it);
        int longest{1};
        for (int &it : nums)
        {
            if (st.find(it - 1) == st.end())
            {
                int count{1}, x{it};
                while (st.find(x + 1) != st.end())
                {
                    count++;
                    x += 1;
                }
                longest = max(longest, count);
            }
        }

        return longest;
    }
};

/*Better Approach
int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int longest{1}, count{}, lastSmall{INT_MIN};
        for (int i{}; i < nums.size(); i++)
        {
            if (nums[i] - 1 == lastSmall)
            {
                count += 1;
                lastSmall = nums[i];
            }
            else if (lastSmall != nums[i])
            {
                count = 1;
                lastSmall = nums[i];
            }
            longest = max(count, longest);
        }
        return longest;
    }

*/

// Brute Force Method : Go for each element in the array and Search for the (element+1) , if true count++ else reset;