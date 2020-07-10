class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> AM, BM;
        int mA, mB, mAG=INT_MIN, mBG=INT_MIN;
        for(int i=0;i<A.size();i++) {
            AM[A[i]]++;
            if(AM[A[i]] > mAG){
                mAG = AM[A[i]];
                mA = i;
            }
        }
        mA = A[mA];
        for(int i=0;i<B.size();i++) {
            BM[B[i]]++;
            if(BM[B[i]] > mBG){
                mBG = BM[B[i]];
                mB = i;
            }
        }
        mB = B[mB];
        if(mAG>=mBG) {
            int count = 0;
            for(int i=0;i<A.size() && i<B.size();i++) {
                if(A[i] != mA && B[i] == mA) {
                    count++;
                }
            }
            if(count == A.size() - mAG) return count;
        }
        else{
            int count = 0;
            for(int i=0;i<A.size() && i<B.size();i++) {
                if(B[i] != mB && A[i] == mB) {
                    count++;
                }
            }
            if(count == B.size() - mBG) return count;
        }
        return -1;
    }
};


//Alternative Better Approach
int minDominoRotations(vector<int>& A, vector<int>& B) {
    vector<int> countA(7), countB(7), same(7);
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        countA[A[i]]++;
        countB[B[i]]++;
        if (A[i] == B[i])
            same[A[i]]++;
    }
    for (int i  = 1; i < 7; ++i)
        if (countA[i] + countB[i] - same[i] == n)
            return n - max(countA[i], countB[i]);
    return -1;
}