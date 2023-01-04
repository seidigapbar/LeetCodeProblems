class Solution {
public:
    bool isAnagram(string s, string t) {
        int sChars[26], tChars[26];
        
        memset(sChars, 0, sizeof(sChars));
        memset(tChars, 0, sizeof(tChars));
        
        for(const auto x : s){
            sChars[x - 97]++;
        }
        
        for(const auto x : t){
            tChars[x - 97]++;
        }
        
        for(auto i = 0; i < 26; i++){
            if(tChars[i] != sChars[i])
                return false;
        }
        
        return true;
    }
};
