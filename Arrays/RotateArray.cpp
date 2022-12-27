# Solution #1 :

/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        size_t sizeOfArray = nums.size();
        k = k % sizeOfArray;
        vector<int> tempVec;
        
        for(int i = k; i > 0; i--){
            tempVec.push_back(nums[sizeOfArray - i]);
        }
        
        for(int i = 0; i < sizeOfArray - k; i++){
            tempVec.push_back(nums[i]);
        }
        
        nums = tempVec;
    }
};
*/
