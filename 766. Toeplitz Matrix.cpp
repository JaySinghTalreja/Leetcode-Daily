class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        unordered_map<int, int> dv;
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[i].size();j++) {
                //Solution One
                /*if(i > 0 && j > 0 && matrix[i][j] != matrix[i-1][j-1]) {
                    return false;
                }
                */
                if(dv.find(i-j) == dv.end()) {
                    dv.insert({i-j, matrix[i][j]});
                }
                else{
                    if(matrix[i][j] != dv[i-j]) {
                        return false;
                    }
                }
            }
        }
        return true; 
    }
};