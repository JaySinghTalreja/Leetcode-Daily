
//O(N) //Linear
class Solution {
public:
    unordered_map<int, int> varMap;
    int solve(string &S, int index) {
        if(varMap.find(index) != varMap.end()) {
            return varMap[index];
        }
        if((index == S.size() - 1 && S[index] != '0') || index == S.size()) {
            return 1;
        }
        if(S[index] == '0') {
            return 0;
        }
        string temp = S.substr(index, 2);
        if(stoi(temp) > 0 && stoi(temp) <=26) {
            return varMap[index] = solve(S, index+2) + solve(S, index+1);
        }
        return varMap[index] = solve(S, index+1);
    }
    int numDecodings(string s) {
        return solve(s, 0);
    }
};


//Iterative Solution
int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='0') dp[i]=0;
            else {
                dp[i] = dp[i+1];
                if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) dp[i]+=dp[i+2];
            }
        }
        return s.empty()? 0 : dp[0];   
    }
