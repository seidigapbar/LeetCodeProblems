# I am not proud about both of these solutions:
class Solution {
public:
    int myAtoi(string s) {
        size_t start = 0, stringSize = s.size();
        int finalResult = 0, sign = 1;
        
        while(s[start] == ' ' && start < stringSize){
            start++;
        }
        
        if(s[start] == '-'){
            sign = -1;
            start++;
        } else if (s[start] == '+'){
            start++;
        }
        
        while(s[start] >= '0' && s[start] <= '9' && start < stringSize){
            int currentDigit = (int)s[start] - 48;
            
            if(sign == 1){
                if(finalResult >= INT_MAX/10){
                    if(finalResult == INT_MAX/10 && currentDigit <= INT_MAX % 10
                      && (start + 1 == stringSize || s[start + 1] < '0' || s[start + 1] > '9'))
                    {
                        return finalResult * 10 + (currentDigit * sign);
                    }
                        return INT_MAX;
                }
            }
            
            else{
                if(finalResult <= INT_MIN/10){
                    if(finalResult == INT_MIN/10 && currentDigit <= abs(INT_MIN % 10)
                      && (start + 1 == stringSize || (s[start + 1] < '0' || s[start + 1] > '9')))
                    {
                        return finalResult * 10 + (currentDigit * sign);
                    }
                        return INT_MIN;
                }
            }
            
            finalResult = finalResult * 10 + (currentDigit * sign);
            start++;
        }
        
        return finalResult;
    }
}; 

class Solution {
public:
    int myAtoi(string s) {
        bool whitespace = true, firstzero = true;
        int8_t pos = 1;
        int returnRes = 0; //48 - 57 //43 (+), 45 (-)
        for(const auto x : s){
            if((int(x) == 45 || int(x) == 43) && whitespace)
            {
                whitespace = false;
                if(int(x) == 45)
                    pos = -1;
            }
            else if(int(x) >= 48 && int(x) <= 58)
            {
                if(firstzero){
                    firstzero = 48/int(x);
                    whitespace = false;
                    }
                if(returnRes > INT_MAX/10 || returnRes < INT_MIN/10)
                    if(pos == 1){
                        returnRes = INT_MAX;
                        return returnRes;
                    }
                    else{
                        returnRes = INT_MIN;
                        return returnRes;
                    }
                else if(returnRes == INT_MAX/10 || returnRes == INT_MIN/10)
                {
                    if(pos == 1 && int(x) - 48 >= 8)
                    {
                        returnRes = INT_MAX;
                        return returnRes;
                    }
                    else if(pos == -1 && int(x) - 48 >= 9){
                        returnRes = INT_MIN;
                        return returnRes;
                    }
                    returnRes = returnRes*10 + pos * (int(x) - 48);    
                }
                else
                    returnRes = returnRes*10 + pos * (int(x) - 48);
            }
            else if((int(x) < 48 || int(x) > 58) && int(x) != 32)
            {
                break;
            }
            else if(int(x) == 32 && !whitespace)
                break;
        }

        return returnRes;

    }
};
