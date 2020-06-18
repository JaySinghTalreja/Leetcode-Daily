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

//Time O(n*m*(m+m))


//Alternative
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
        return "";
        string ans=strs[0];
        int max=INT_MAX;
        for(auto& s:strs)
        {
            if(s.length()==0)
            return "";
            int i=0;
            for(i=0;i<ans.length()&&i<s.length();i++)
            {
                if(s[i]!=ans[i])
                break;
            }
            ans=ans.substr(0,i);
        }

        return ans;
    }
};
//Time O(n*m)



https://leetcode.com/problems/longest-common-prefix/discuss/6910/Java-code-with-13-lines