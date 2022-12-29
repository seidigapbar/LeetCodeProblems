# Proper solution:

class Solution {
public:
    int reverse(int x) {
        int res = 0, lastDigit = 0;
        
        while(x != 0){
            lastDigit = x % 10;
            x = x / 10;
            if(res > INT_MAX / 10 || res < INT_MIN / 10){
                return 0;
            }
            else if ((res == INT_MAX / 10 && lastDigit > 7) || (res == INT_MIN / 10 && lastDigit < -8)){
                return 0;
            }
            res = 10 * res + lastDigit;
        }
        
        return res;
    }
};

# This is the ugliest solution in my life:

class Solution {
public:
    int reverse(int x) {
        const string MAX_INT32 = "2147483647";
        const string MIN_INT32 = "-2147483648";
               
        if (x == 0)
            return 0;

        while(x % 10 == 0 && abs(x) > 0){
            x = x / 10;
        }
        
        string s = to_string(x);
        size_t stringLength = s.size();

        if (stringLength > MAX_INT32.size() && x > 0 || stringLength > MIN_INT32.size() && x < 0){
            return 0;
        }

        
        for (auto i = 0; i < stringLength / 2; i++){
            if (x > 0){
                swap(s[i], s[stringLength - 1 - i]);
            }
            else{
                swap(s[i+1], s[stringLength - 1 - i]);
            }
        }
        
        if (stringLength == MAX_INT32.size() && x > 0 || stringLength == MIN_INT32.size() && x < 0){
            for (auto i = 0; i < stringLength; i++){
                    if(x < 0){
                        if(s[i] > MIN_INT32[i]){
                            return 0;
                        } else if(s[i] < MIN_INT32[i]){
                            return stoi(s);
                        }
                    }
                else{
                    if(s[i] > MAX_INT32[i]){
                        return 0;
                    } else if(s[i] < MAX_INT32[i]){
                            return stoi(s);
                        }
                }
            }
        }
        
        int result = stoi(s);
        return result;
    }
};
