class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> A;
        for(int i=0;i<numRows;i++) {
            vector<int> R;
            for(int j=0;j<i+1;j++) {
                if(i==0 || i==1 || j == 0 || j == i) {
                    R.push_back(1);
                }
                else {
                    R.push_back(A[i-1][j]+A[i-1][j-1]);
                }
            }
            A.push_back(R);
        }
        return A;
    }
};
