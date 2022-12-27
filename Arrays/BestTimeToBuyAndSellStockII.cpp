class Solution {
public:
    int maxProfit(vector<int>& prices) {
    // If the array sorted in decreasing order then 0
    // if the array is sorted in increasing order then last element minus first
        size_t sizeOfArray = prices.size();
        int maxProfit = 0;
        for (size_t i = 1; i < sizeOfArray; i++){
            if (prices[i-1] < prices[i])
            {
                maxProfit += prices[i] - prices[i-1];
            }
        }
        return maxProfit;
    }
};
