class Solution {
public:
    int check(string &s, int left, int right) {
        unordered_map<char, int> count;
        for(int i=left;i<=right;i++) {
            count[s[i]]++;
        }
        return count.size();
    }
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charCount;
        int left = 0, right = 0;
        int maxCharCount = 0;
        int maxLength = 0;
        while(right < s.size()) {
            maxCharCount = max(maxCharCount, ++charCount[s[right]]);
            while(maxCharCount + k < right-left+1) {
                --charCount[s[left]];
                left++;
            }
            maxLength = max(maxLength, right-left+1);
            right++;
        }
        return maxLength;
    }
    
};