class Solution {
public:
    unordered_map<string, int> varMap;
    static bool compr(string &f, string &s) {
        return f.size() < s.size();
    }
    int solve(string &W, unordered_set<string> &varSet) {
        
        if(varMap.find(W) != varMap.end()) {
            return varMap[W];
        }
        int n = W.size();
        int ans = 1;
        for(int i=n-1;i>=0;i--) {
            string temp = W.substr(0, i) + W.substr(i+1);
            if(varSet.find(temp) != varSet.end()) {
                ans = max(ans, 1 + solve(temp, varSet));
            }
        }
        return varMap[W] = ans;
        
    }
    int longestStrChain(vector<string>& words) {
        //sort(words.begin(), words.end(), compr);
        unordered_set<string> varSet;
        varSet.insert(words.begin(), words.end());
        int ans = 0;
        for(auto W: words) {
            ans = max(ans,solve(W, varSet));
        }
        return ans;
    }
};

//Time Complexity N = len(words)
//W = len(word)
//O((NW)^2)