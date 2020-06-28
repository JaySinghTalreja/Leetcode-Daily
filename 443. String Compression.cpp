class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() < 2){
            return chars.size();
        }
        int index=0,count;
        int nc = 0;
        while(index < chars.size()) {
            char currentChar = chars[index];
            count = 0;
            while(index<chars.size() && chars[index] == currentChar) {
                index++;count++;
            }
            chars[nc++] = currentChar;
            if(count >= 2){
                for(auto A: to_string(count)){
                    chars[nc++] = A;
                }
            }
        }
        return nc;
    }
};