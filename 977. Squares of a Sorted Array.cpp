class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> P(A.size(), 0);
        int n = A.size();
        int i=0, j=n-1;
        for(int k = n-1;k>=0;k--) {
            if(abs(A[i]) > abs(A[j])) {
                P[k] = A[i] * A[i];
                i++;
            }
            else{
                P[k] = A[j] * A[j];
                j--;
            }
        }
        return P;
    }
};