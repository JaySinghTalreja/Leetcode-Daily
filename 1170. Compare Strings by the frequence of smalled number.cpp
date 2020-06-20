/*
Input: queries = ["cbd"], words = ["zaaaz"]
Output: [1]
Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").


Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
Output: [1,2]
Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").

*/
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> counts(12, 0);
        vector<int> result;
        //Lambda Function
        auto C = [](string s) {
            return count(s.begin(), s.end(), *min_element(s.begin(), s.end()));
        };
        for(auto A : words){
            for(int i=C(A)-1;i>=0;i--) {
                counts[i]++;
            }
        }
        for(auto A: queries) {
            result.push_back(counts[C(A)]);     //Elements Having Frequence more than current query in Words.
        }
        return result;
    }
};


//Same problem could be done using binary search