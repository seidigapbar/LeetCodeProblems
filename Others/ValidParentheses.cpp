class Solution {
public:
    bool isValid(string s) {
        // '(', ')', '{', '}', '[' and ']'
        stack<char> parentheses;
        map<char, char> opposites = {{'}', '{'}, {']', '['}, {')' , '('}};
        for(auto c : s){
            switch(c){
                case '(':
                case '{':
                case '[':
                    parentheses.push(c);
                    break;
                case ')':
                case '}':
                case ']':
                    if(parentheses.empty() || parentheses.top() != opposites[c]){
                        return false;
                    } else{
                        parentheses.pop();
                    }
                    break;
            }
        }
        
        return parentheses.empty();
    }
};
