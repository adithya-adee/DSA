
class Solution
{
public:
    pair<int, int> getFloorAndCeil(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        int floor = -1, ceil = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                // Exact match found; both floor and ceil are the target
                return {nums[mid], nums[mid]};
            }
            else if (nums[mid] > target)
            {
                ceil = mid;      // Current element is a potential ceil
                right = mid - 1; // Search in the left half
            }
            else
            {
                floor = mid;    // Current element is a potential floor
                left = mid + 1; // Search in the right half
            }
        }

        // Return actual values, or -1 if floor/ceil do not exist
        int floorValue = (floor == -1) ? -1 : nums[floor];
        int ceilValue = (ceil == -1) ? -1 : nums[ceil];

        return {floorValue, ceilValue};
    }
};
