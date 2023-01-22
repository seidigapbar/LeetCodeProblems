// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //Bin search
        int leftPos = 0, rightPos = n;
        while(leftPos < rightPos){
            int middle = leftPos + (rightPos - leftPos) / 2;
            if(isBadVersion(middle)){
                rightPos = middle;
            } else{
                leftPos = middle + 1;
            }
        }
        return leftPos;
    }
};
