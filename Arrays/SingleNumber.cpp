class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Did not really know about the XOR operator, looked it up.
        // My ideas were to sort the array, but it's O(n log n) or to use the map but it's not
        // constant space.
        int result = 0;
        for(const auto &x : nums){
            result ^= x;
        }
        return result;
    }
};
