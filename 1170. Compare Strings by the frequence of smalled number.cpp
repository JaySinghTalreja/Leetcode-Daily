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
            result.push_back(counts[C(A)]);
        }
        return result;
    }
};


//Same problem could be done using binary search