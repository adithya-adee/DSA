class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if (prices.size() == 1)
            return 0;

        int maxSum{INT_MIN}, minNum{prices[0]};

        for (int i{}; i < prices.size(); i++)
        {
            int diff{prices[i] - minNum};
            if (diff < 0)
            {
                minNum = prices[i];
            }
            else
                maxSum = max(diff, maxSum);
        }
        return maxSum;
    }
};

/* Optimal Approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy = INT_MAX;
        for (auto& price : prices) {
            profit = max(profit, price - buy);
            buy = min(price, buy);
        }
        return profit;
    }
};

*/

/* Brute Force Approach : Time limit exceeded
#define opt() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        opt();
        int maxSum{INT_MIN};
        if(prices.size() == 1) return 0;
        for(int i{};i<prices.size()-1;i++){
            int temp{prices[i]};
            for(int j{i+1};j<prices.size();j++){
                int diff{prices[j]-prices[i]};
                if(diff < 0) diff = 0;
                maxSum = max(diff,maxSum);
            }

        }
        return maxSum;
    }
};*/