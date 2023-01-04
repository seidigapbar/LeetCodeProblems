# Good enough

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t haystackSize = haystack.size(), needleSize = needle.size();
        
        if (needleSize > haystackSize){
            return -1;
        }
        
        for (auto i = 0; i < haystackSize - needleSize + 1; i++){
            if (haystack[i] == needle[0]){
                for (auto j = 0; j < needleSize; j++){
                    if (needle[j] != haystack[i + j]){
                        break;
                    }
                    if (j == needleSize - 1){
                        return i;
                    }
                }
            }
        }
        
        return -1;
    }
};
