class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> R;
        vector<vector<int>> prev{{1},{1, 1}};
        if(rowIndex <2) {
            return prev[rowIndex];
        }
        for(int i=2;i<rowIndex+1;i++) {
            R.clear();
            R.push_back(1);
            for(int j=1;j<i;j++) {
                R.push_back(prev[1][j-1] + prev[1][j]);
            }
            R.push_back(1);
            prev.pop_back();
            prev.push_back(R);
        }
        return R;
    }
};


//Alternative O(k) solution
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> A(rowIndex+1, 0);
        A[0] = 1;
        for(int i=1; i<rowIndex+1; i++)
            for(int j=i; j>=1; j--)
                A[j] += A[j-1];
        return A;
    }
};


//Furthur Alternative
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ints(rowIndex + 1, 1);
        for(int row = 0; row < rowIndex; row++) {
            for(int col = row; col > 0; col--) {
                ints[col] += ints[col - 1];
            }
        }
        return ints;
    }
};


//Alterniave O(K) Time || Same Space
vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex+1,1);
    int small = rowIndex/2;
    long comb = 1;
    int j = 1;
    for (int i=rowIndex; i>=small; i--){
        comb *= i;
        comb /= j;
        j ++;
        ans[i-1] = (int)comb;
        ans[j-1] = (int)comb;
    }
    return ans;
}
