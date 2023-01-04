class Solution {
public:
    void reverseString(vector<char>& s) {      
        size_t sizeOfString = s.size();
        for (auto i = 0; i < sizeOfString / 2; i++){
            swap(s[i], s[sizeOfString - i - 1]);
        }
    }
};
