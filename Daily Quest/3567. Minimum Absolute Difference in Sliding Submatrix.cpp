class Solution {
public:
    
    int getMinDiff(multiset<int>& ms) {
        if (ms.size() < 2) return 0;

        int minDiff = INT_MAX;

        auto it = ms.begin();
        auto prev = it;
        it++;

        while (it != ms.end()) {
            if (*it != *prev) {  // distinct only
                minDiff = min(minDiff, *it - *prev);
            }
            prev = it;
            it++;
        }

        return (minDiff == INT_MAX) ? 0 : minDiff;
    }

    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));

        for (int i = 0; i <= n - k; i++) {

            multiset<int> ms;

            // Build first window
            for (int x = i; x < i + k; x++) {
                for (int y = 0; y < k; y++) {
                    ms.insert(grid[x][y]);
                }
            }

            ans[i][0] = getMinDiff(ms);

            // Slide right
            for (int j = 1; j <= m - k; j++) {

                // Remove left column
                for (int x = i; x < i + k; x++) {
                    ms.erase(ms.find(grid[x][j - 1]));
                }

                // Add right column
                for (int x = i; x < i + k; x++) {
                    ms.insert(grid[x][j + k - 1]);
                }

                ans[i][j] = getMinDiff(ms);
            }
        }

        return ans;
    }
};