class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int sum  =0;
        int count = 1;
        int nc;
        for(int i=0;i<S.size();i++) {
            sum += widths[S[i] - 'a'];
            if(sum >100) {
                count++;
                sum=widths[S[i]-'a'];
            }
            
        }
        return {count, sum};
    }
};

