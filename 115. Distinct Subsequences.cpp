class Solution {
public:
    
    int solve(string &S, string &T) {
        vector<vector<long int>> DP(T.size()+1, vector<long int>(S.size()+1, 0));
        
        for(int i=0;i<=S.size();i++) {
            DP[0][i] = 1;
        }
        
        for(int i=1;i<=T.size();i++) {
            DP[i][0] = 0;
        }
        
        for(int i=1;i<=T.size();i++) {
            for(int j=1;j<=S.size();j++) {
                if(T[i-1] == S[j-1]) {
                    DP[i][j] = DP[i-1][j-1] + DP[i][j-1];
                }
                else {
                    DP[i][j] = DP[i][j-1];
                }
            }
        }
        /*
        for(auto R: DP) {
            for(auto C: R) {
                cout<<C<<" ";
            }
            cout<<endl;
        }
        */
        return DP[T.size()][S.size()];
    }
    /*unordered_map<string, int> varMap;
    int solve(string &S, string &T, int i, int j) {
        string cache = to_string(i) + "|" + to_string(j);
        if(varMap.find(cache) != varMap.end()) {
            return varMap[cache];
        }
        if(j < 0) {
            return 1;
        }
        if(i < 0 && j >= 0) {
            return 0;
        }
        if(S[i] == T[j]) {
            return varMap[cache] = solve(S, T, i-1, j-1) + solve(S, T, i-1, j);
        }
        return varMap[cache] = solve(S, T, i-1, j);
    }
    */
    
    int numDistinct(string s, string t) {
        //return solve(s, t, s.size()-1, t.size()-1); //Recursive + Memoization
        return solve(s, t);
    }
};