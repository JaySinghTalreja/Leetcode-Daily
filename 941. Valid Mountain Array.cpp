class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        bool flag = false;
        if(n <=2 || A[0] > A[1]) {
            return false;
        }
        for(int i=2;i<n;i++) {
            if(A[i] < A[i-1]) {
                flag = true;
            }
            else if(flag == true || A[i] == A[i-1]) {
                return false;
            }
        }
        return flag;
    }
};