class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //track korte hobe: 9 rows, 9 columns, ar 9 ta boxes
        bool row[9][9] = {};
        bool col[9][9] = {};
        bool box[9][9] = {};

        for (int i = 0; i< 9; i++){
            for (int j = 0; j< 9; j++){
                //khali hole check krar drkar nei
                if (board[i][j] == '.'){
                    continue;
                }

                int num = board[i][j] - '1';

                int boxIndex = (i/3) * 3 + (j/3);

                 if (row[i][num] ||
                    col[j][num] ||
                    box[boxIndex][num]) {
                    return false;
                }

                 row[i][num] = true;

                // Mark this digit as seen in its column.
                col[j][num] = true;

                // Mark this digit as seen in its 3x3 box.
                box[boxIndex][num] = true;
            }
        }
        return true;
    }
};