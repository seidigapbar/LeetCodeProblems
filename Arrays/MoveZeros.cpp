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
