class Solution {
public:
    bool checkVowel(char s) {
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U') {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        //unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.length();
        int frontPointer = 0;
        int lastPointer = n-1;
        while(frontPointer < lastPointer) {
            if(checkVowel(s[frontPointer]) && checkVowel(s[lastPointer])) {
                swap(s[frontPointer], s[lastPointer]);
                frontPointer++;
                lastPointer--;
            }
            else if(checkVowel(s[frontPointer])) {
                lastPointer--;
            }
            else if(checkVowel(s[lastPointer])) {
                frontPointer++;
            }
            else{
                frontPointer++;
                lastPointer--;
            }
        }
        return s;
    }
};