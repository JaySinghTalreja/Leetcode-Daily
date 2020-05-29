class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        const int N = words1.size();
        unordered_map<string, unordered_set<string>> similar;
        for (auto& pair : pairs) {
            similar[pair[0]].insert(pair[1]);
            similar[pair[1]].insert(pair[0]);
        }
        for (int i = 0; i < N; ++i) {
            if (words1[i] != words2[i] && !similar[words1[i]].count(words2[i])) {
                return false;
            }
        }
        return true;
    }
};


/*

LINKS:https://massivealgorithms.blogspot.com/2018/05/leetcode-734-sentence-similarity.html
LINKS:https://blog.csdn.net/fuxuemingzhu/article/details/100999877

Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.
For example, “great acting skills” and “fine drama talent” are similar, if the similar word pairs are pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].
Note that the similarity relation is not transitive. For example, if “great” and “fine” are similar, and “fine” and “good” are similar, “great” and “good” are not necessarily similar.
However, similarity is symmetric. For example, “great” and “fine” being similar is the same as “fine” and “great” being similar.
Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.
Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].
Note:
The length of words1 and words2 will not exceed 1000.
The length of pairs will not exceed 2000.
The length of each pairs[i] will be 2.
The length of each words[i] and pairs[i][j] will be in the range [1, 20].

*/