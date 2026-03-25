class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<long long> rowSum(m,0);
        vector<long long> colSum(n,0);

        long long total=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                total += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];

            }
        }

        if(total %2 !=0){
            return false;
        }

        long long upper =0;
        for(int i=0;i<m-1;i++){
            upper += rowSum[i];
            if(upper == total - upper){
                return true;
            }
        }
        long long left =0;
        for(int j=0;j<n-1;j++){
            left += colSum[j];
            if(left == total - left){
                return true;
            }
        }
            return false;
        
    }

};