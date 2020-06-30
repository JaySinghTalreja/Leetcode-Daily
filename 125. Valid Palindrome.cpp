class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() <= 1) return true;
        int left = 0;
        int right = s.size()-1;
        //bool flag = false;
        //cout<<"right:"<<right<<endl;
        while(left <= right) {
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            else if(!isalnum(s[right])) {
                right--;
                continue;
            }
            if(tolower(s[left]) != tolower(s[right])) {
                //cout<<left<<" "<<right<<endl;
                //cout<<s[left]<<" "<<s[right]<<endl;
                return false;
                //flag = true;
            }
            left++;
            right--;
        }
        return true;
    }
};