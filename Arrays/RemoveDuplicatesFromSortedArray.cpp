class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int itemIndex = 1, prevNum = nums[0];
        for (const auto &x : nums){
            if(x != prevNum){
                prevNum = x;
                nums[itemIndex] = prevNum;
                itemIndex++;
            }
        }
        return itemIndex;
    }
};
