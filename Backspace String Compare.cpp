class Solution {
public:
    bool backspaceCompare(string S, string T) {
        while(S.find('#') != string::npos) {
            int index = S.find('#');
            if(index == 0) {
                S.erase(index, 1);
                continue;
            }
            S.erase(index-1, 1);   //For Character
            S.erase(index-1, 1);  //For #
        }
        while(T.find('#') != string::npos) {
            int index = T.find('#');
            if(index == 0) {
                T.erase(index, 1);
                continue;
            }
            T.erase(index-1, 1);   //For Character
            T.erase(index-1, 1);  //For #
        }
        bool result = S.compare(T) ? false : true;
        return result;
    }
};

/**PYTHON CODE
 class Solution(object):
    def backspaceCompare(self, S, T):
        def F(S):
            skip = 0
            for x in reversed(S):
                if x == '#':
                    skip += 1
                elif skip:
                    skip -= 1
                else:
                    yield x

        return all(x == y for x, y in itertools.izip_longest(F(S), F(T)))
*/