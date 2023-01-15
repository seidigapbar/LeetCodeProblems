class Solution {
public:
    int countPrimes(int n){
        int cnt = 0, maxNum = sqrt(n);
        vector<bool> erathosthesesSquare(n, false);
        for(auto i = 2; i < n; i++){
            if(erathosthesesSquare[i] == true){
                continue;
            }
            cnt++;
            for(auto x = (uint64_t)i * i; x < n; x += i){
                erathosthesesSquare[x] = true;
            }
        }
        return cnt;
    }
};
