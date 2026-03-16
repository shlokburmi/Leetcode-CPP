class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> d1(m, vector<int>(n)), d2(m, vector<int>(n));

        // diag "\" prefix
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                d1[i][j] = grid[i][j];
                if(i>0 && j>0) d1[i][j] += d1[i-1][j-1];
            }
        }

        // diag "/" prefix
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                d2[i][j] = grid[i][j];
                if(i>0 && j+1<n) d2[i][j] += d2[i-1][j+1];
            }
        }

        set<int> st;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                // size 0 rhombus
                st.insert(grid[i][j]);

                for(int k=1;;k++){

                    if(i+2*k>=m || j-k<0 || j+k>=n) break;

                    int sum = 0;

                    // top -> right
                    sum += d1[i+k][j+k] - (i>0 && j>0 ? d1[i-1][j-1] : 0);

                    // right -> bottom
                    sum += d2[i+2*k][j] - (i+k-1>=0 && j+k+1<n ? d2[i+k-1][j+k+1] : 0);

                    // bottom -> left
                    sum += d1[i+2*k][j] - (i+k-1>=0 && j-k-1>=0 ? d1[i+k-1][j-k-1] : 0);

                    // left -> top
                    sum += d2[i+k][j-k] - (i-1>=0 && j+1<n ? d2[i-1][j+1] : 0);

                    // subtract the 4 corners counted twice
                    sum -= grid[i][j];
                    sum -= grid[i+k][j+k];
                    sum -= grid[i+2*k][j];
                    sum -= grid[i+k][j-k];

                    st.insert(sum);
                }
            }
        }

        vector<int> ans(st.begin(), st.end());
        sort(ans.rbegin(), ans.rend());
        if(ans.size()>3) ans.resize(3);
        return ans;
    }
};