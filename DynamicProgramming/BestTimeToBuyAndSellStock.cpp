# Not a dp problem

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX, profit = 0;
        for(auto i = 0; i < prices.size(); i++){
            buy = min(buy, prices[i]);
            if(prices[i] - buy > profit){
                profit = prices[i] - buy;
            }
        }
        return profit;
    }
};
