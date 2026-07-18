// Last updated: 18/07/2026, 20:04:17
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> boxes[9];
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                char val = board[i][j];
                int box = (i/3)*3+(j/3); // used to determine the box element belongs to out of 9 boxes indexed [0,8]
                if(row[i].count(val) or col[j].count(val) or boxes[box].count(val)){
                    return false;
                }
                row[i].insert(val);
                col[j].insert(val);
                boxes[box].insert(val);
            }
        }
        return true;
    }
};