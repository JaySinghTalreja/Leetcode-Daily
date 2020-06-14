
class Solution {
public:
    bool checkRecord(string S) {
        int n = S.length();
        if(n<2){
            cout<<"NOW";
            return true;
        }
        int ca =0, cl =0;
        for(int i=0;i<n;i++) {
            if(S[i] == 'A'){
                ca++;
                if(ca>1){
                    return false;
                }
            }
            else if(S[i] == 'L') {
                cl++;
                if(i>1 && S[i-1] == 'L' && S[i-2] == 'L') {
                    cout<<i<<" ";
                    return false;
                }
            }
        }
        return true;
    }
};


//Better Way of Calculating L
class Solution {
public:
    bool checkRecord(string s) {
    int a=0, l=0;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='A') a++;
        if(s[i]=='L') l++;
        else l=0;
        if(a>=2||l>2) return false;
    }
    return true;
}
};

//Without REGEX Java
public boolean checkRecord(String s) {
    return !s.contains("LLL") && (s.indexOf("A") == s.lastIndexOf("A"));
}


