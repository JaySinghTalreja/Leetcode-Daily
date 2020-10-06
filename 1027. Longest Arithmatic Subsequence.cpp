class Solution {
public:
    bool check(vector<int> &seq) {
        if(seq.size() < 2) {
            return false;
        }
        int commDiff = seq[1] - seq[0];
        for(int i=2;i<seq.size();i++) {
            if(seq[i] - seq[i-1] != commDiff) return false;
        }
        return true;
    }
    int cnt = 0;
    void solve(vector<int> &A, int index, vector<int> &seq) {
        if(index == A.size()) {
            if(check(seq)) {
                int s = seq.size();
                cnt = max(cnt, s);
            }
            return;
        }
        seq.push_back(A[index]);
        solve(A, index+1, seq);
        seq.pop_back();
        solve(A, index+1, seq);
    }
    int longestArithSeqLength(vector<int>& A) {
        vector<int> seq;
        solve(A, 0, seq);
        return cnt;
    }
};

//Time - O(2^n * N) Finding All Subsequences take O(2^N) && Checking if it's an AP takes N;
