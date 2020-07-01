class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        for(auto A: words){
            cout<<A<<" ";
        }
        unordered_set<string> s;
        string ans = "";
        for(int i=0;i<words.size();i++) {
            if(words[i].length() == 1 || s.find(words[i].substr(0, words[i].size()-1)) != s.end()){
                s.insert(words[i]);
                ans = (words[i].length() > ans.length()) ? words[i] : ans;
            }
        }
        return ans;
    }
};