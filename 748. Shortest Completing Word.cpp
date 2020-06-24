class Solution {
public:
    bool check(string &word, map<char, int> &m) {
        for(auto A:m) {
            if(count(word.begin(), word.end(), A.first) < A.second){
                return false;;
            }
        }
        return true;
    }
    string shortestCompletingWord(string lP, vector<string>& words) {
        map<char, int> s;
        for(auto A: lP) {
            if(isalpha(A)) s[tolower(A)]++;
        }
        string sol="";
        for(int i=0;i<words.size();i++) {
            if(check(words[i], s) && (sol.length() == 0 || sol.length()>words[i].length())) {
                sol = words[i];
            }
        }
        return sol;
    }
};