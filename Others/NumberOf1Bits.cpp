class Solution {
public:
    int hammingWeight(uint32_t n) {
        # Very elegant solution I found on the internet:
        int cnt = 0;
        
        while(n != 0){
            n = n & (n-1) // Least Significant Bit is set to 0, while the previous 0 are changed to 1. But it does not really matter in this case since we take an operator of "&". Advantage of this method is that we actually run the loop only N times where N is the number of 1's in binary representation of a given number. Pretty neat.
            cnt++;
        }
        
        return cnt;
    }
};


class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t a = 1;
        int cnt = 0;
        
        while(n != 0){
            if(a & n){
                cnt++;
            }
            n = n >> 1;
        }
        
        return cnt;
    }
};
