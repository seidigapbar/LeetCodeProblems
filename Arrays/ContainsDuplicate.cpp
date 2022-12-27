class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> duplicates;
        for(const auto &x : nums){
            if(duplicates.find(x) == duplicates.end()){
                duplicates.insert(x);
            }
            else{
                return true;
            }
        }
        return false;
    }
};

# If we want to have O(1) memory: 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t numsSize = nums.size();
        for(auto i = 1; i < numsSize; i++){
            if(nums[i-1] == nums[i]){
                return true;
            }
        }
        return false;
    }
};
