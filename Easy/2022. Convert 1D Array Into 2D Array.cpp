class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() !== m*n)
            return {};
        
        vector<vector<int>> matrix(m,vector<int>(n));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    construct2DArray[i][j]=original[k];
                    k++;
                }
            }
        return matrix;
        )

        
    }
};