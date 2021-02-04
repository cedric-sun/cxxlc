// cesun, 9/2/20 4:23 PM.

#include <vector>

using std::vector;

constexpr static int di[] = {0, 1, 0, -1};
constexpr static int dj[] = {1, 0, -1, 0};

class Solution {
public:
    vector<vector<char>> *gridp;
    int nRow, nCol;

    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) {
            return 0;
        }
        gridp = &grid;
        int ans = 0;
        nRow = grid.size();
        nCol = grid[0].size();
        for (int i = 0; i < nRow; ++i) {
            for (int j = 0; j < nCol; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }

    void dfs(int i, int j) {
        (*gridp)[i][j] = 'x';
        for (int k = 0; k < 4; ++k) {
            const int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && ni < nRow && nj >= 0 && nj < nCol && (*gridp)[ni][nj] == '1')
                dfs(ni, nj);
        }
    }
};
