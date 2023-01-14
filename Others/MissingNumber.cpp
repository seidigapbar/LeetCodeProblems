class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = (nums.size() * (1+nums.size())) / 2;
        for (const auto i : nums){
            result -= i;
        }
        return result;
    }
};
