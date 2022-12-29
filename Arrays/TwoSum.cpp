class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t sizeOfArray = nums.size();
        
        /*
        // Brute force solution : 
        for (auto i = 0; i < sizeOfArray; i++){
            for (auto j = 0; j < sizeOfArray; j++){
                if (nums[i] + nums[j] == target && i != j){
                    return {i, j};
                }
            }
        }
        
        return {-100, -100};
        */
        
        unordered_map<int, int> goalPos;
        
        for (auto i = 0; i < sizeOfArray; i++){
            if (goalPos.count(nums[i]) > 0){
                return {goalPos[nums[i]], i};
            }            
            goalPos[target - nums[i]] = i;
        }
        return {-1, -1};
    }
};
