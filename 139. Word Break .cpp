class Solution {
public:
    unordered_map<string, bool> varMap;
    bool solve(string s, vector<string>& wordDict, unordered_map<string,bool> &dict) {
        string cache = s;
        if(varMap.find(cache) != varMap.end()) {
            //cout<<"\nCached";
            return varMap[cache];
        }
        if(dict[s]) {
            return true;
        }
        
        for(int i=1; i<s.size(); i++) {
            string tempOne = s.substr(0, i);
            string tempTwo = s.substr(i);
            bool isPossible = solve(tempOne, wordDict, dict) && solve(tempTwo, wordDict, dict);
            if(isPossible) {
                return varMap[cache] = true;
            }
        }
        return varMap[cache] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dict;
        for(auto W : wordDict) {
            dict[W] = true;
        }
        return solve(s, wordDict, dict);
    }
};

//Time Complexity O(n3) , Space O(n^2) ;
//Also Refer https://www.techiedelight.com/word-break-problem/


//klternative
bool wordBreak(string s, vector<string>& wordDict) {
        int n =s.size();
        
        set<string> dict;
        for(auto w: wordDict)
            dict.insert(w);
        
        vector<bool> dp(n+1,false);
        dp[0] = true; //You can make empty string with any wordDict
        
        //From every i position check if you can make word ending here
        for(int i=1;i<n;i++)
        {
            //If we can make a word from j->i
            //We need to check if we can make a word till j first
            for(int j=i-1;j>=0;j--)
            {
                string curr = s.substr(j,i-j); //pos,noOfChars
                
                if(dict.find(curr)!=dict.end())
                    dp[i] = dp[i] || dp[j]; //dp[j] means can be make words before j(dp is 1 indexed)
                
                if(dp[i])
                    break;
            }
        }
        
        return dp[n];
    }


//Better COde
bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.size()==0) return false;
        
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }