    void moveZeroes(vector<int>& nums) {
        size_t sizeOfArray = nums.size();
        for (size_t i = 0; i < sizeOfArray; i++){
            if(nums[i] == 0){
                for (size_t j = i + 1; j < sizeOfArray; j++){
                    if(nums[j] != 0){
                        swap(nums[i], nums[j]);
                        break;
                        }
                }
            }
        }
    }




# Better solution: 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t currentPos = 0, sizeOfArray = nums.size(), numberOfZeros = 0;
        
        for (auto i = 0; i < sizeOfArray; i++){
            if (nums[i] != 0){
                nums[currentPos++] = nums[i];
            }
        }
        
        for (auto i = currentPos; i < sizeOfArray; i++){
            nums[i] = 0;
        }
    }
};
