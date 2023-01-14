class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {{1}, {1,1}};
        
        if(numRows == 0){
            return vector<vector<int>> {{}};
        } else if(numRows == 1){
            return vector<vector<int>> {{1}};
        } else if(numRows == 2){
            return result;
        }
        
        numRows = numRows - 2;
        int cnt = 2;
        
        while(numRows > 0){
            result.push_back(vector<int> {});
            result[cnt].push_back(1);
            for(auto i = 0; i < result[cnt-1].size() - 1; i++){
                result[cnt].push_back(result[cnt-1][i] + result[cnt-1][i+1]);
            }
            result[cnt].push_back(1);
            cnt++;
            numRows--;
        }
        return result;
    }
};
