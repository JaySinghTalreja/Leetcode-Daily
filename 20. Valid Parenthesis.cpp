class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(int i=0;i<s.length();i++) {
            if(check.empty()) {
                //cout<<s[i];
                check.push(s[i]);
            }
            else if(s[i] == ')' && s[i]-1 == check.top())  {
                check.pop();
            }
            else if((s[i] == '}' || s[i] == ']') && s[i] - 2 == check.top())             {
                check.pop();
            }
            else{
                
                check.push(s[i]);
            }
        }
        if(!check.empty()) {
            return false;
        }
        return true;
    }
};