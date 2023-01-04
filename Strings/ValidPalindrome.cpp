# Less readable but much faster solution: 

class Solution {
public:
    bool isPalindrome(string s) {
        size_t halfSize = s.size() / 2, stringSize = s.size();
  
        for (auto left = 0, right = 0; left < stringSize, right < stringSize - 1;)
        {
            if(left + right >= stringSize)
                break;
            
            if (s[left] >= 'A' && s[left] <= 'Z'){
                s[left] = s[left] + 32;
            }
            else if ((s[left] > 'z' || s[left] < 'a') && (s[left] > '9' || s[left] <'0')){
                     left++;
                     continue;
            }

            if (s[stringSize - 1 - right] >= 'A' && s[stringSize - 1 - right] <= 'Z'){
                s[stringSize - 1 - right] = s[stringSize - 1 - right] + 32;
            }
            else if ((s[stringSize - 1 - right] > 'z' || s[stringSize - 1 - right] < 'a') && (s[stringSize - 1 - right] > '9' || s[stringSize - 1 - right] < '0')){
                     right++;
                     continue;
            }
            
            if(s[left] != s[stringSize - 1 - right]){
                return false;
            }
                     
            
            left++;
            right++;
        }
        
        return true;
    }
};


# More readable but slower solution:


class Solution {
public:
    bool isPalindrome(string s) {
        string palindrome = convertString(s);
        size_t halfSize = palindrome.size() / 2, stringSize = palindrome.size();
                
        for(auto i = 0; i < halfSize; i++)
        {
            if(palindrome[i] != palindrome[stringSize - i - 1]){
                return false;
            }
        }
        
        return true;
    }
    
    string convertString(string s){
        string returnResult;
        for(auto x : s){
            if ((x >= 'a' && x <= 'z') || (x >= '0' && x <= '9')){
                returnResult += x;
            }
            else if (x >= 'A' && x <= 'Z'){
                x = x + 32;
                returnResult += x;
            }
        }
        
        return returnResult;
    }
};
