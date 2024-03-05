class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> cols(n, false), hills(2 * n - 1, false), dales(2 * n - 1, false);
        return backtrack(0, 0, n, cols, hills, dales);
    }

private:
    int backtrack(int row, int count, int n, vector<bool>& cols, vector<bool>& hills, vector<bool>& dales) {
        for (int col = 0; col < n; ++col) {
            if (couldPlace(row, col, n, cols, hills, dales)) {
                placeQueen(row, col, n, cols, hills, dales);
                if (row + 1 == n) count++;
                else count = backtrack(row + 1, count, n, cols, hills, dales);
                removeQueen(row, col, n, cols, hills, dales);
            }
        }
        return count;
    }

    bool couldPlace(int row, int col, int n, vector<bool>& cols, vector<bool>& hills, vector<bool>& dales) {
        return !(cols[col] + hills[row - col + n - 1] + dales[row + col]);
    }

    void placeQueen(int row, int col, int n, vector<bool>& cols, vector<bool>& hills, vector<bool>& dales) {
        cols[col] = true;
        hills[row - col + n - 1] = true;
        dales[row + col] = true;
    }

    void removeQueen(int row, int col, int n, vector<bool>& cols, vector<bool>& hills, vector<bool>& dales) {
        cols[col] = false;
        hills[row - col + n - 1] = false;
        dales[row + col] = false;
    }
};
