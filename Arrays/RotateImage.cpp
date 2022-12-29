class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Fastest solution:
        size_t heightOfArray = matrix.size(), lengthOfArray = matrix[0].size();
        for (auto i = 0; i < lengthOfArray; i++){
            vector<int> line;
            for (int j = heightOfArray - 1; j >= 0; j--){
                line.push_back(matrix[j][i]);
            }
            matrix.push_back(line);
        }
        
        for (auto i = 0; i < heightOfArray; i++){
            auto it = matrix.begin();
            matrix.erase(it);
        }
        
        /* Using reverse method which is not intuitive for me:
        size_t heightOfArray = matrix.size(), lengthOfArray = matrix[0].size();    
        reverse(matrix.begin(), matrix.end());
        for(size_t i = 0; i < heightOfArray; i++){
            for(size_t j = i + 1; j < lengthOfArray; j++){
                swap (matrix[j][i], matrix[i][j]);
            }
        }
        */
    }
};
