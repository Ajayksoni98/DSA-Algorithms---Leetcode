class Solution {
public:
    int m, n;

    bool check(vector<vector<int>> &grid, int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    bool solve(vector<vector<int>>& grid, int x, int y) {

        if (x == m - 1 && y == n - 1)
            return true;

        int val = grid[x][y];
        grid[x][y] = 0; 

        if (val == 1) {

            // Right
            if (check(grid, x, y + 1) &&
                (grid[x][y + 1] == 1 ||
                 grid[x][y + 1] == 3 ||
                 grid[x][y + 1] == 5)) {

                if (solve(grid, x, y + 1))
                    return true;
            }

            // Left
            if (check(grid, x, y - 1) &&
                (grid[x][y - 1] == 1 ||
                 grid[x][y - 1] == 4 ||
                 grid[x][y - 1] == 6)) {

                if (solve(grid, x, y - 1))
                    return true;
            }

        }

        else if (val == 2) {

            // Up
            if (check(grid, x - 1, y) &&
                (grid[x - 1][y] == 2 ||
                 grid[x - 1][y] == 3 ||
                 grid[x - 1][y] == 4)) {

                if (solve(grid, x - 1, y))
                    return true;
            }

            // Down
            if (check(grid, x + 1, y) &&
                (grid[x + 1][y] == 2 ||
                 grid[x + 1][y] == 5 ||
                 grid[x + 1][y] == 6)) {

                if (solve(grid, x + 1, y))
                    return true;
            }

        }

        else if (val == 3) {

            // Left
            if (check(grid, x, y - 1) &&
                (grid[x][y - 1] == 1 ||
                 grid[x][y - 1] == 4 ||
                 grid[x][y - 1] == 6)) {

                if (solve(grid, x, y - 1))
                    return true;
            }

            // Down
            if (check(grid, x + 1, y) &&
                (grid[x + 1][y] == 2 ||
                 grid[x + 1][y] == 5 ||
                 grid[x + 1][y] == 6)) {

                if (solve(grid, x + 1, y))
                    return true;
            }

        }

        else if (val == 4) {

            // Right
            if (check(grid, x, y + 1) &&
                (grid[x][y + 1] == 1 ||
                 grid[x][y + 1] == 3 ||
                 grid[x][y + 1] == 5)) {

                if (solve(grid, x, y + 1))
                    return true;
            }

            // Down
            if (check(grid, x + 1, y) &&
                (grid[x + 1][y] == 2 ||
                 grid[x + 1][y] == 5 ||
                 grid[x + 1][y] == 6)) {

                if (solve(grid, x + 1, y))
                    return true;
            }

        }

        else if (val == 5) {

            // Left
            if (check(grid, x, y - 1) &&
                (grid[x][y - 1] == 1 ||
                 grid[x][y - 1] == 4 ||
                 grid[x][y - 1] == 6)) {

                if (solve(grid, x, y - 1))
                    return true;
            }

            // Up
            if (check(grid, x - 1, y) &&
                (grid[x - 1][y] == 2 ||
                 grid[x - 1][y] == 3 ||
                 grid[x - 1][y] == 4)) {

                if (solve(grid, x - 1, y))
                    return true;
            }

        }

        else if (val == 6) {

            // Right
            if (check(grid, x, y + 1) &&
                (grid[x][y + 1] == 1 ||
                 grid[x][y + 1] == 3 ||
                 grid[x][y + 1] == 5)) {

                if (solve(grid, x, y + 1))
                    return true;
            }

            // Up
            if (check(grid, x - 1, y) &&
                (grid[x - 1][y] == 2 ||
                 grid[x - 1][y] == 3 ||
                 grid[x - 1][y] == 4)) {

                if (solve(grid, x - 1, y))
                    return true;
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        return solve(grid, 0, 0);
    }
};