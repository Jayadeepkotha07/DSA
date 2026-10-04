class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int startRow = 0, startCol = 0;
        int emptyCells = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != -1)
                    emptyCells++;

                if (grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
            }
        }
        return dfs(grid, startRow, startCol, emptyCells);
    }
private:
    int dfs(vector<vector<int>>& grid, int row, int col, int remaining) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row >= rows || col < 0 || col >= cols ||
            grid[row][col] == -1) {
            return 0;
        }
        if (grid[row][col] == 2) {
            return remaining == 1 ? 1 : 0;
        }
        int original = grid[row][col];
        grid[row][col] = -1;
        int paths = 0;
        paths += dfs(grid, row + 1, col, remaining - 1);
        paths += dfs(grid, row - 1, col, remaining - 1);
        paths += dfs(grid, row, col + 1, remaining - 1);
        paths += dfs(grid, row, col - 1, remaining - 1);
        grid[row][col] = original;
        return paths;
    }
};