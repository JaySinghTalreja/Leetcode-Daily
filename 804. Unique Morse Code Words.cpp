class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> codes;
        for(int i=0;i<words.size();i++) {
            string sol = "";
            for(auto ch: words[i]) {
                sol += morse[ch-'a'];
            }
            codes.insert(sol);
        }
        return codes.size();
    }
};


//Time Complexity -> O(nm)
//or O(N) if size of word vector(n) is greater than m.