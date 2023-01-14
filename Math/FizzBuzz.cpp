class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        int divisionByThree = 1, divisionByFive = 1;
        for(auto i = 1; i <= n; i++){
            if(divisionByThree == 3 && divisionByFive == 5){
                result.push_back("FizzBuzz");
                divisionByThree = 1;
                divisionByFive = 1;
            } else if(divisionByThree == 3){
                result.push_back("Fizz");
                divisionByThree = 1;
                divisionByFive++;
            } else if(divisionByFive == 5){
                result.push_back("Buzz");
                divisionByFive = 1;
                divisionByThree++;
            } else{
                divisionByThree++;
                divisionByFive++;
                result.push_back(to_string(i));
            }
        }
        return result;
    }
};
