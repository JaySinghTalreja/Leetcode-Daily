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
        return 0;           //If we coudnt' find the endWord;
    }
};

//Time Complexity O(N X M^2) , Where is the Number os words in Word List and M is the size of maximum Word
//Space O(N x M^2)


//Practiced Again
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,  bool> words;
        for(auto &var : wordList) {
            words[var] = true;
        }
        if(words.find(endWord) == words.end()) {
            return 0;
        }
        queue<pair<string, int>> varQueue;
        varQueue.push({beginWord, 1});
        int count = 0;
        unordered_map<string, bool> visited;
        while(!varQueue.empty()) {
            pair<string, int> temp = varQueue.front();
            varQueue.pop();
            visited[temp.first] = true;
            if(temp.first == endWord) {
                return temp.second;
            }
            int tempSize = temp.first.size();
            for(int i=0;i<temp.first.size();i++) {
                for(int j=0;j<26;j++) {
                    char nextChar = 'a' + j;
                    string nextString = temp.first.substr(0, i) + nextChar + temp.first.substr(i+1);
                    if(words.find(nextString) != words.end() && visited.find(nextString) == visited.end()) {
                        varQueue.push({nextString, temp.second+1});
                    }
                }
            }
        }
        return 0;
    }
};

//Complexity Analysis : LEETCODE
