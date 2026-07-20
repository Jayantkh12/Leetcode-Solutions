class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        while (k--) {
            vector<vector<int>> temp = grid;

            temp[0][0] = grid[n - 1][m - 1];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (j < m - 1)
                        temp[i][j + 1] = grid[i][j];
                    else if (i < n - 1)
                        temp[i + 1][0] = grid[i][j];
                }
            }

            grid = temp;
        }

        return grid;
    }
};