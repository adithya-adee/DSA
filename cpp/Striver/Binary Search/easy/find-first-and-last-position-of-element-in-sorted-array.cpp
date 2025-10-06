class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = -1, right = -1;

        // Find the leftmost occurrence of the target
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                left = mid;  // Temporarily store the left index
                r = mid - 1; // Continue searching on the left side
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        // If no occurrence of target was found, return [-1, -1]
        if (left == -1)
            return {-1, -1};

        // Find the rightmost occurrence of the target
        l = left, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                right = mid; // Temporarily store the right index
                l = mid + 1; // Continue searching on the right side
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return {left, right};
    }
};
