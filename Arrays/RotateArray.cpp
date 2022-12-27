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

# Solution #2 (partially finished, could not come up with ending): 

/*
void rotate(vector<int>& nums, int k) {
    size_t sizeOfArray = nums.size(), iterations = 0;
    k = k % sizeOfArray;
    // Move the first element
    size_t currentIdx = k;
    int prevVal = nums[k];
    nums[k] = nums[0];

    // Once we return to the first element we are done.
    // TODO: Should somehow find if there is a cycle to move to the next array
    while(iterations < sizeOfArray){
        if (currentIdx + k >= sizeOfArray){
            currentIdx = currentIdx + k - sizeOfArray;
            int tempVal = prevVal;
            prevVal = nums[currentIdx];
            nums[currentIdx] = tempVal;
        }
        else{
            currentIdx += k;
            int tempVal = prevVal;
            prevVal = nums[currentIdx];
            nums[currentIdx] = tempVal;
        }
        iterations++;
    }
}
*/

# Solution #3 (Looked it up on the internet ngl)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        size_t sizeOfArray = nums.size();
        
        if(sizeOfArray < 2){
            return;
        }
        
        k = k % sizeOfArray;
        
        reverseArray(nums, 0, sizeOfArray - k - 1);
        reverseArray(nums, sizeOfArray - k, sizeOfArray - 1);
        reverseArray(nums, 0, sizeOfArray - 1);
    }
private:
    void reverseArray(vector<int> &nums, size_t firstElem, size_t lastElem){
        int tempLen = lastElem - firstElem;
        if(tempLen > 0){
            for (auto i = 0; i < tempLen / 2 + 1; i++){
                swap(nums[firstElem + i], nums[lastElem - i]);
            }
        }
    }
};
