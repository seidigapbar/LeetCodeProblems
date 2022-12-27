    vector<int> plusOne(vector<int>& digits) {
        int sizeOfArray = digits.size();
        bool bitShift = true;
        
        for (int i = sizeOfArray - 1; i >= 0 && bitShift; i--){
            if (digits[i] == 9){
                digits[i] = 0;
                bitShift = true;
                if(i == 0){
                    digits.insert(digits.begin(), 1);
                }
            }
            else{
                digits[i] += 1;
                bitShift = false;
            }
        }
        
        return digits;
    }
