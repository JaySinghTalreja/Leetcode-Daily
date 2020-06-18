class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t n = strs.size();
        if(n <=1) return (n==1 ? strs[0] : "");
        string prefix = strs[0];
        for(int i=1;i<n;i++) {
            while(strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0,prefix.length()-1);
            }
        }
        return prefix;
    }
};