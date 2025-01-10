class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;
        int preSum = 0, cnt = 0;
        mpp[0] = 1;
        for (int num : nums)
        {
            preSum += num;
            if (mpp.find(preSum - k) != mpp.end())
            {
                cnt += mpp[preSum - k];
            }
            mpp[preSum]++;
        }
        return cnt;
    }
};

// class Solution {
// public:
//     int subarraySum(vector<int>& arr, int k) {
//         unordered_map<long long, int> mp;
//         int count=0,n=arr.size();
//         long long sum=0;

//         for(int i=0;i<n;i++){
//             sum+=arr[i];

//             if(sum==k){
//                 count++;
//             }

//             long long rem=sum-k;
//             if(mp.find(rem)!=mp.end()){
//                 count+=mp[rem];
//             }
//             mp[sum]++;
//         }

//         return count;
//     }
// };
