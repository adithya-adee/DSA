// Opitimal Solution is reverse array approach

class Solution
{
public:
    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};

/*
Efficient code
int n = nums.size();
if (n == 0)
    return;
  k = k % n;
  if (k > n)
    return;

    vector<int> temp(k);
  for (int i = n - k; i < n; i++)
  {
    temp[i - n + k] = nums[i];
  }
  for (int i = n - k - 1; i >= 0; i--)
  {
    nums[i + k] = nums[i];
  }
  for (int i = 0; i < k; i++)
  {
    nums[i] = temp[i];
  }
*/

/*
This is brute force and causes time limit exceed
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size(),temp = 0;
        for(int i{};i<k;i++){
            temp = nums[len -1];
            for(int j=len-1;j>0;j--){
                swap(nums[j],nums[j-1]);
            }
            nums[0] = temp;
        }
    }
};*/