class Solution {
public:
    bool isPowerOfThree(int n) {
        const double epsilon = 1e-12;
        double log_3_n = log(n) / log(3);
        return abs(log_3_n - round(log_3_n)) < epsilon;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        int pow = 1;
        while(pow <= n){
            if(pow != n && pow >= INT_MAX / 3){
                return false;
            } else if(pow == n){
                return true;
            } else{
                pow *= 3;
            }
        }
        return false;
    }
};
