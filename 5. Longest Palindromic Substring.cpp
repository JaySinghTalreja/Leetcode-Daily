
//O(n^2) Time 
//O(N^2) Space

class Solution {
public:
    string findPalindromes(string &S, vector<vector<bool>> &pCheck) {
        int rows = pCheck.size();
        int cols = pCheck[0].size();
        
        for(int i=0;i<rows;i++) {
            pCheck[i][i] = true;
        }
        string maxString = S.substr(0, 1);
        for(int i=rows-2;i>=0;i--) {
            for(int j=i+1;j<cols; j++) {
                if(S[i] != S[j]) {
                    pCheck[i][j] = false;
                }
                else{
                    pCheck[i][j] = (j-i==1) ? true : pCheck[i+1][j-1];
                    if(pCheck[i][j]) {
                        string temp = S.substr(i, j-i+1);
                        if(temp.size() > maxString.size()) {
                            maxString = temp;
                        }
                    }
                }
            }
        }
        
        /*
        for(auto R: pCheck) {
            for(auto C: R) {
                cout<<C<<" ";
            }
            cout<<endl;
        }
        */
        
        return maxString;
    }
    string longestPalindrome(string S) {
        if(S.size() == 1) {
            return S;
        }
        vector<vector<bool>> pCheck(S.size(), vector<bool>(S.size(), false));
        return findPalindromes(S, pCheck);
        /*
        string maxString = "";
        for(int i=0;i<S.size();i++) {
            for(int j = i;j<S.size();j++) {
                if(pCheck[i][j] == true) {
                    string temp = S.substr(i, j-i+1);
                    if(temp.size() > maxString.size()) {
                        maxString = temp;
                    }
                }
            }
        }
        return maxString;
        */
    }
};

