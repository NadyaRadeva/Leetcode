class Solution {
public:
    const int ROWS[4] = {0, 0, 1, -1};
    const int COLS[4] = {1, -1, 0, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    ++fresh;
                } else if (grid[row][col] == 2) {
                    q.push({row, col});
                }
            }
        }

        if (fresh == 0) {
            return 0;
        }

        int mins = -1;

        while (!q.empty()) {
            int size = q.size();
            ++mins;

            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();

                for (int j = 0; j < 4; ++j) {
                    int nr = r + ROWS[j];
                    int nc = c + COLS[j];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        --fresh;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return (fresh == 0) ? mins : -1;
    }
};
