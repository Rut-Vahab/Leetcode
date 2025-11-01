class Solution {
public:

    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, n));
        
        for (auto &m : mines) {
            grid[m[0]][m[1]] = 0;
        }
        
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                count = (grid[i][j] == 0 ? 0 : count + 1);
                grid[i][j] = min(grid[i][j], count);
            }
            count = 0;
            for (int j = n - 1; j >= 0; --j) {
                count = (grid[i][j] == 0 ? 0 : count + 1);
                grid[i][j] = min(grid[i][j], count);
            }
        }
        for (int j = 0; j < n; ++j) {
            int count = 0;
            for (int i = 0; i < n; ++i) {
                count = (grid[i][j] == 0 ? 0 : count + 1);
                grid[i][j] = min(grid[i][j], count);
            }
            count = 0;
            // למטה → למעלה
            for (int i = n - 1; i >= 0; --i) {
                count = (grid[i][j] == 0 ? 0 : count + 1);
                grid[i][j] = min(grid[i][j], count);
            }
        }
        
        // חיפוש המקסימום
        int maxOrder = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                maxOrder = max(maxOrder, grid[i][j]);
        
        return maxOrder;
    }
};

