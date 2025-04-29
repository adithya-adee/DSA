#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        size_t n{nums.size()};
        set<vector<int>> res;
        for (int i{}; i < n; i++)
        {
            set<int> hashset;
            for (int j{i + 1}; j < n; j++)
            {
                int third = -(nums[i] + nums[j]);
                if (hashset.find(third) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    res.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(res.begin(), res.end());

        return ans;
    }
}

;

int main()
{
    Solution s1;
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    const vector<vector<int>> matrix{s1.threeSum(nums)};
    for (const vector<int> &mat : matrix)
    {
        for (const int &m : mat)
        {
            cout << m << " ";
        }
        cout << endl;
    }
}