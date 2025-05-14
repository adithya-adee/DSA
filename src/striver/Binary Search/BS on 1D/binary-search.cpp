#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int binary_search(vector<int> &arr, int target, int start, int end)
    {
        if (start > end)
            return -1;

        int mid = (end % 2 == 0) ? (start + end) / 2 : (start + end) / 2 + 1;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;

        return -1;
    }
};

int main()
{
    Solution s1;
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 4;
    int start = 0;
    int end = arr.size();
    int position = s1.binary_search(arr, target, start, end);
    cout << position;
    return 0;
}