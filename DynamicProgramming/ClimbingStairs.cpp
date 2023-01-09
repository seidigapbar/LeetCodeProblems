class Solution {
public:
    int climbStairs(int n) {
        /* //recurisve solution:
        static map<int, int> memMap;
        memMap[0] = 0;
        memMap[1] = 1;
        memMap[2] = 2;
        
        if(memMap.count(n)){
            return memMap[n];
        }
        
        memMap[n] = climbStairs(n - 1) + climbStairs(n - 2);
        
        return memMap[n]; */
        // Iterative solution:
        int climbingFirst = 1, climbingSecond = 2, result = 2;
        
        if(n <= climbingSecond){
            return n;
        }
        
        while(n > 2){
            result = climbingFirst + climbingSecond;
            climbingFirst = climbingSecond;
            climbingSecond = result;
            n--;
        }
        return result;
    }
};
