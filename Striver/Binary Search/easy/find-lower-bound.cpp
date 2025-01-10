
class Solution
{
public:
    int findFloor(vector<int> &arr, int k)
    {
        if (arr[0] > k)
            return -1;
        int n = arr.size(), left = 0, right = n - 1, ans = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] == k)
                return mid;
            else if (arr[mid] < k)
            {
                ans = mid;
                left = mid + 1;
            }
            else if (arr[mid] > k)
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};
