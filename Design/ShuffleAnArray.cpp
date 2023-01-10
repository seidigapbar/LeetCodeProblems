# Do not understand the randomizing part:


class Solution {
private:
    vector<int> nums;

public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        size_t numsSize = this->nums.size(), randIndex;
        vector<int> numsCopy = nums;
        for(auto i = 0; i < numsSize; i++){
            randIndex = rand() % (numsSize - i);
            swap(numsCopy[i], numsCopy[i + randIndex]);
        }
        return numsCopy;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
