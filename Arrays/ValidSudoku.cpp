class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool horizontal = true, vertical = false;

        bool answer = checkLine(board, horizontal) && checkLine(board, vertical) && checkSquare(board);
        
        return answer;
    }
    
private: 
    bool checkLine(vector<vector<char>> &board, bool horizontal){
        int x, y;
        for (auto i = 0; i < 9; i++){
            unordered_set<char> values;
            for(auto j = 0; j < 9; j++){
                if (horizontal){
                    x = j, y = i;
                }
                else{
                    x = i, y = j;
                }
                if (board[x][y] != '.' && values.find(board[x][y]) == values.end()){
                    values.insert(board[x][y]);
                }
                else if(board[x][y] != '.'){
                    return false;
                }
            }
        }
        return true;
    }
    
    
    bool checkSquare(vector<vector<char>> &board){
        auto horizontalStart = 0, horizontalEnd = 2, verticalStart = 0, verticalEnd = 2, cnt = 0;
        vector<int> moveRight = {3, 3, -6}, moveDown = {0, 0, 3};
        
        
        while(horizontalEnd < 10 && verticalEnd < 10){
            if (checkSingleSquare(board, horizontalStart, horizontalEnd, verticalStart, verticalEnd) == false){
                return false;
            }
            horizontalStart += moveRight[cnt % 3];
            horizontalEnd += moveRight[cnt % 3];
            verticalStart += moveDown[cnt % 3];
            verticalEnd += moveDown[cnt % 3];
            cnt++;
        }
        return true;
    }
    
    bool checkSingleSquare(vector<vector<char>> &board, int horizontalStart, int horizontalEnd, int verticalStart, int verticalEnd){
        unordered_set<char> numbers;
        for (auto i = verticalStart; i <= verticalEnd; i++){
            for (auto j = horizontalStart; j <= horizontalEnd; j++){
                if (board[i][j] != '.' && numbers.find(board[i][j]) == numbers.end()){
                    numbers.insert(board[i][j]);
                }
                else if (board[i][j] != '.'){
                    return false;
                }
            }
        }
        return true;
    }
    
};
