class Solution {
public:
    int romanToInt(string s) {
        int finalNumber = 0, stringLen = s.size();
        map<char, char> smallerDivisionGroup = {{'M', 'C'}, {'D', 'C'}, {'L', 'X'}, 
                                                {'C', 'X'}, {'X', 'I'}, {'V', 'I'}};
        map<char, int> charToInt = {{'M', 1000}, {'D', 500}, {'C', 100},
                                    {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        
        for(auto i = stringLen - 1; i >= 0; i--){
            finalNumber += charToInt[s[i]];
            if(i != 0 && s[i - 1] == smallerDivisionGroup[s[i]]){
                finalNumber -= charToInt[s[i-1]];
                i--; // Step up to another division group
            }
        }
        return finalNumber;
    }
};
