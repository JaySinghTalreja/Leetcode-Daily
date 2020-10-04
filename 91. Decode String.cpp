
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