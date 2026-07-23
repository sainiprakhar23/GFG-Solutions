class Solution {
public:

    // 8 possible Knight moves
    int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
    int dy[8] = {1, -1, 2, -2, -2, 2, -1, 1};

    bool fillMatrix(int i, int j, int move, int n, vector<vector<int>>& result) {

        if (i < 0 || j < 0 || i >= n || j >= n || result[i][j] != -1) {
            return false;
        }
        
        if (move == n * n - 1) {
            result[i][j] = move;
            return true;
        }
        result[i][j] = move;

        for (int k = 0; k < 8; k++) {

            int newRow = i + dx[k];
            int newCol = j + dy[k];

            if (fillMatrix(newRow, newCol, move + 1, n, result)) {
                return true;
            }
        }

        /*
        // ---------- Another way (without for loop) ----------

        if(fillMatrix(i+2, j+1, move+1, n, result)) return true;
        if(fillMatrix(i+2, j-1, move+1, n, result)) return true;
        if(fillMatrix(i+1, j+2, move+1, n, result)) return true;
        if(fillMatrix(i+1, j-2, move+1, n, result)) return true;
        if(fillMatrix(i-1, j-2, move+1, n, result)) return true;
        if(fillMatrix(i-1, j+2, move+1, n, result)) return true;
        if(fillMatrix(i-2, j-1, move+1, n, result)) return true;
        if(fillMatrix(i-2, j+1, move+1, n, result)) return true;
        */

        // ---------------- Backtracking ----------------
        // None of the moves worked, so unmark this cell
        result[i][j] = -1;

        return false;
    }

    vector<vector<int>> knightTour(int n) {

        vector<vector<int>> result(n, vector<int>(n, -1));
        int i = 0;
        int j = 0;
        int move = 0;

        if (fillMatrix(i, j, move, n, result)) {
            return result;
        }
        return {};
    }
};