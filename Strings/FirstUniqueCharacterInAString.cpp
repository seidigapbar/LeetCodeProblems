# Best solution I could come up with:

class Solution {
public:
    int firstUniqChar(string s) {
        const int MAXLENGTH = s.size();
        int indices[26], result = MAXLENGTH;
        fill(indices, indices+26, MAXLENGTH);

        for (auto i = 0; i < MAXLENGTH; i++){
            if(indices[s[i] - 97] == MAXLENGTH){
                indices[s[i] - 97] = i;
            }
            else{
                indices[s[i] - 97] = -1;
            }
        }
        
        for (auto x : indices){
            if (x != -1){
                result = min(x, result);
            }
        }
        
        if (result == MAXLENGTH)
            return -1;
        
        return result;
    }
};

# My first solution:

class Solution {
public:
    int firstUniqChar(string s) {

        map<char, int> uniqueLetters;
        set<char> duplicatedLetters;
        size_t stringSize = s.size();
        
        for (auto i = 0; i < stringSize; i++){
            if (duplicatedLetters.find(s[i]) != duplicatedLetters.end()){
                continue;
            }
            else if (uniqueLetters.find(s[i]) != uniqueLetters.end()){
                duplicatedLetters.insert(s[i]);
                uniqueLetters.erase(s[i]);
            }
            else {
                uniqueLetters[s[i]] = i;
            }
        }
        
        if(uniqueLetters.empty()){
            return -1;
        }
        
        int result = 1000000; // More than 10^5
        
        for (const auto i : uniqueLetters){
            result = min(result, i.second);
        }
        
        return result;
    }
};


# Solution I thought would work because I was deceived by the GPT-3 about sorting maps according to their values

class Solution {
public:
    int firstUniqChar(string s) {
       struct compare_value{
           bool operator()(const pair<char, int>& lhs, const pair<char, int>& rhs) const{
               return lhs.second < rhs.second;
           }
       };
        map<char, int, compare_value> uniqueLetters;
        set<char> duplicatedLetters;
        size_t stringSize = s.size();
        
        for (auto i = 0; i < stringSize; i++){
            if (duplicatedLetters.find(s[i]) != duplicatedLetters.end()){
                continue;
            }
            else if (uniqueLetters.count(s[i]) > 1){
                duplicatedLetters.insert(s[i]);
                uniqueLetters.erase(s[i]);
            }
            else {
                uniqueLetters[s[i]] = i;
            }
        }
        
        if(uniqueLetters.empty()){
            return -1;
        }
        return uniqueLetters.begin()->second;
    }
};
