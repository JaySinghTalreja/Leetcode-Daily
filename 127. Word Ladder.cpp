class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> varSet(wordList.begin(), wordList.end());
        queue<string> varQueue;
        varQueue.push(beginWord);
        int ladder = 1;
        while(!varQueue.empty()) {
            int D = varQueue.size();
            for(int E=0;E<D;E++) {
                string temp = varQueue.front();
                varQueue.pop();
                if(temp == endWord) {
                    return ladder;
                }
                varSet.erase(temp);  // To Not Revist Same Word Again
                int n = temp.size();
                for(int i=0;i<n;i++) {
                    for(int k=0;k<26;k++) {
                        char A = 'a' + k;
                        string newString = temp.substr(0, i) + A + temp.substr(i+1);
                        if(varSet.find(newString) != varSet.end()) {
                            varQueue.push(newString);
                        }
                    }
                }
            }
            ladder++;
        }
        return 0;
    }
};

//Time Complexity O(N X M) , Where is the Number os words in Word List and M is the size of maximum Word