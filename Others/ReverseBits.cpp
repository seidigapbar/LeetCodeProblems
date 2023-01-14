// No better I could find
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0, cnt = 31;
        while (n){
            ans = (1 & n) * pow(2, cnt) + ans;
            cnt--;
            n = n >> 1;
        }
        return ans;
    }
};
