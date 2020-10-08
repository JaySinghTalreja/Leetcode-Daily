class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [&](string A, string B) {
            return A < B;
        });
        string finalString = "";
        for(int i=0;i<d.size();i++) {
            string &temp = d[i];
            int left = 0, right = 0;
            //bool flag = true;
            while(left <s.size() && right < temp.size()) {
                while( left < s.size() && s[left] != temp[right]) {
                    left++;
                }
                if(left == s.size() && right < temp.size()) {
                    break;
                }
                left++;
                right++;
            }
            if(right == temp.size()  && finalString.size() < temp.size()) {
                finalString = temp;
            }
        }
        return finalString;
    }
};
// o(NlogN + N*M + K) Where N = Number of words in dictionary, M = Word with maximum Length, and K = Length of the Given String with which we a comparing.