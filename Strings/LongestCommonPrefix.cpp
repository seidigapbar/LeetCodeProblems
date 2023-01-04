# TODO: CHECK OUT THE SOLUTIONS FROM LEETCODE TEAM


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size())
            return "";
        
        string ans, first = strs[0];
        size_t stringCount = strs.size(), firstSize = strs[0].size();
        
        for (auto i = 0; i < firstSize; i++){
            for (auto j = 0; j < stringCount; j++){
                if (i >= strs[j].size()){
                    return ans;
                }
                if (strs[j][i] != first[i]){
                    return ans;
                }
            }
            ans += first[i];
        }
        
        return ans;
    }
};
