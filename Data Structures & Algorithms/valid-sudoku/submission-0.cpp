class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<string> seen;

        for (int r = 0; r < 9; r++) {

            for (int c = 0; c < 9; c++) {

                char d = board[r][c];

                if (d == '.')
                    continue;

                if (!seen.insert(string(1, d) + "row" + to_string(r)).second)
                    return false;

                if (!seen.insert(string(1, d) + "col" + to_string(c)).second)
                    return false;

                if (!seen.insert(string(1, d) + "box" +
                                 to_string((r / 3) * 3 + (c / 3))).second)
                    return false;
            }
        }

        return true;
    }
};