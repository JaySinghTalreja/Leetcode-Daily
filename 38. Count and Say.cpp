class Solution {
public:
    string countAndSay(int n) {
        if(n==1) {
            return "1";
        }
        string S = "1$"; //11$
        int count;
        string newS =  "";
        for(int i=1;i<n;i++) {
            count = 0;
            int o = S.length();
            for(int j=0;j<o;j++) {
                if(count == 0) {
                    count = 1;
                }
                else if(S[j] == S[j-1]){
                    count++;
                }
                else{
                    newS += to_string(count) + S[j-1];
                    count = 1;
                }
            }
            newS += '$';
            S = newS;
            newS = "";
        }
        S.pop_back();
        return S;
    }
};